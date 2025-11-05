#include <iostream>
#include <string>
#include <queue>

using namespace std;

/*
Challenge #53: Sand Bars 🏝️
You are given a two-dimensional grid representing an area of ocean. 
Some cells contain sand bars (represented by 1) while others are just water (represented by 0). 
An "island" is formed by connecting adjacent sand bars horizontally or vertically (not diagonally). 
You need to count the total number of islands in the grid.

Input Format 📝
The first line contains two integers n and m representing the dimensions of the grid (rows and columns).
The next n lines contain m binary digits each (0 or 1), representing the grid of sand bars and water.

Output Format 🖥️
An integer representing the number of distinct islands in the grid.
*/
int main(){
    int y, x;
    string str;
    cin >> y >> x;
    getline(cin, str);

    unsigned char arr[y*x];
    int temp;
    for(int i=0; i<y; i++){
        getline(cin, str);
        for(int j=0; j<x; j++){
            arr[j+i*x]=(str.at(j)-'0');
        }
    }

    queue<int> line = queue<int>();
    int islandCount=0;
    int index=0;

    int offsets[4] = {-1, -x, 1, x};
    while(index<x*y){
        while(!line.empty()){
            int i = line.front();
            line.pop();
            if((arr[i] & 2)==0){
                for(int j=0; j<4; j++){
                    temp = i + offsets[j];
                    if(0<=temp && temp < x*y){
                        if((arr[temp] & 1) == 1 && (arr[temp] & 2) == 0){line.push(temp);}
                    }
                }
            }
            arr[i] |= 2;
        }
        index++;
        if((arr[index]&1) == 1 && (arr[index]&2) == 0){line.push(index); islandCount++;}
    }

    cout << islandCount << endl;

    return 0;
}