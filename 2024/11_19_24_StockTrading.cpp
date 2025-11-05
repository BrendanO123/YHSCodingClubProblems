#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>

using namespace std;

/*
Best Time to Buy and Sell Stock

You are given a string of comma-separated integers representing an array of `prices` where `prices[i]` is 
the price of a given stock on day `i`.

You want to maximize your profit by choosing a _single day_ to buy one stock and choosing a different day in the 
future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0. 
You may assume all stock prices to be positive integers or zero.
*/
int main(){
    int temp;
    string str;

    stringstream ss;
    getline(cin, str);
    for(int i=0; i<str.size(); i++){if(str.at(i) == ','){str.at(i)=' ';}}
    ss<<str;

    vector<int> arr = vector<int>();
    while(ss.good()){
        ss>>temp;
        arr.push_back(temp);
    }
    int size = arr.size()-1;

    int diff[size];
    for(int i=0; i<size; i++){diff[i]=arr.at(i+1)-arr.at(i);}

    int CS=0;
    int max = INT_LEAST32_MIN;
    bool pos=false;
    for(int i=0; i<size; i++){
        CS += diff[i];
        if(CS<0){CS=0;}
        if(CS>max){max=CS;}
    }
    cout << max << endl;

    return 0;
}