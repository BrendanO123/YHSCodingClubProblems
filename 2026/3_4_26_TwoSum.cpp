#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;


/*
Two Sum

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Input Format

A space separated array of numbers, followed by a target number on the next line.

Output Format

Two space separated integers representing the indices of the two numbers that add up to the target.
*/
int main(){
    //Input
    string temp; stringstream ss;
    getline(cin, temp); ss << temp;

    vector<int> arr = vector<int>();
    unordered_map<int,int> map = unordered_map<int,int>();

    pair<int,int> solution = pair<int,int>(-1,-1);
    for(int i = 0; !ss.bad() && !ss.eof(); i++){
        int a; ss >> a;
        if(ss.bad()){break;}
        arr.emplace_back(a);
        if(map.find(a) != map.end()){ // the only way for duplicate elements to have exactly one solution is if
                                        // they collectively add to N together. I.E., they are both one half of N
            solution = pair<int,int>(i, map.at(a));
        }
        else{map.emplace(a, i);}
    }
    int n; cin >> n;

    if(solution != pair<int,int>(-1,-1)){
        cout << solution.first << ' ' << solution.second << endl;
        return 0;
    }
    for(int i = 0; i < arr.size(); i++){
        if(map.find(n - arr.at(i)) != map.end()){
            if(i != map.at(n - arr.at(i))){
                cout << i << ' ' << map.at(n - arr.at(i)) << endl;
                return 0;
            }
        }
    }
    return 0;
}