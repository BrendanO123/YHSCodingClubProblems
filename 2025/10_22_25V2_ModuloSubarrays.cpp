#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/*
There are N treasure chests in a row, chest i has a[i] gold coins (yes, some chests are cursed and have negative "gold"). 
You must find the number of subarrays, formed out of consecutive elements of a, whose cumulative sum of a[i] is
exactly divisible by K.

📃 Input Format

N K
a1 a2 ... aN

📝 Output Format

A single integer, the number of subarrays.
*/
inline int plusMod(int a, int m){
    auto e = (a % m);
    return (e < 0 ? e + m : e);
}
int main(){
    string temp;
    int n, m;
    cin >> n >> m; getline(cin, temp);

    int a;
    int count = 0, cumSum = 0;
    unordered_map<int, int> remainderCounts = unordered_map<int, int>();
    remainderCounts.emplace(0, 1);
    for(int i = 0; i < n; i++){
        cin >> a;
        cumSum = plusMod(cumSum + a, m);
        if(remainderCounts.find(cumSum) == remainderCounts.end()){remainderCounts.emplace(cumSum, 1);}
        else{
            count += remainderCounts.at(cumSum);
            remainderCounts.at(cumSum)++;
        }
    }
    cout << count << endl;

    return 0;
}