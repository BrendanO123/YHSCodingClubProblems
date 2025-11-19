#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in 
the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.

Example 1:

Input: nums = 2 3 1 1 4
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.

Example 2:

Input: nums = 3 2 1 0 4
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, 
which makes it impossible to reach the last index.
*/
int main(){
    string str;
    stringstream ss;
    getline(cin, str); ss << str;

    int max, x;
    ss >> max;
    while(!ss.fail() && !ss.eof()){
        ss >> x;
        if(x>--max){max = x;}
        if(max == 0){cout << "false" << endl; return 0;}
    }
    cout << "true" << endl;
    return 0;
}