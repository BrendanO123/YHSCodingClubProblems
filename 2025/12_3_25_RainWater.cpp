#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

/*
Trapping Rain Water

Write a program that, given n non-negative integers representing an elevation map where the width of each bar is 1, 
computes how much water it can trap after raining.

The boundaries of the elevation map do not trap water. (By this, I mean that there is not a "wall" on the 
left and right side of the elevation map; water can flow out.)

Input Format
An comma-separated list of integers.

Output Format
An integer representing the total amount of trapped water.

Test Cases:
Inputs
0 1 0 2 1 0 1 3 2 1 2 1
4 2 0 3 2 5

Outputs
6
9
*/

int main(){
    vector<pair<int,int>> arr = vector<pair<int,int>>();
    
    string str;
    stringstream ss;
    getline(cin, str); ss << str;

    int max1, a;
    ss >> a;
    max1 = a;
    arr.emplace_back(a, a);
    while(!ss.fail() && !ss.eof()){
        ss >> a;
        if(a > max1){max1 = a;}
        arr.emplace_back(a, max1);
    }

    int len = arr.size();
    max1 = arr.at(len-1).first;
    int sum = 0;
    for(int i = len - 2; i>=0; i--){
        a = arr.at(i).first;
        if(a > max1){max1 = a;}
        sum += max(min(max1, arr.at(i).second) - a, 0);
    }

    cout << sum << endl;
    return 0;
}