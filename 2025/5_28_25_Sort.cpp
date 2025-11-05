#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

/*
0-1-2 Sort 🔢

You are given a list of integers, composed of only the numbers zero, one, and two.
Write a program to output a sorted version of the list in a simple, fast way
(without using built in sorting functions).

➡️ Test Cases

Input: 0 0 1 0 1 0 0 2
Output: 0 0 0 0 0 1 1 2

Input: 2 0 1 1 0 2 1 1 1 0 1 2 1 1 0 2 1 1 0 1 0 2 2 2 0 2 0 1 1
Output: 0 0 0 0 0 0 0 0 1 1 1 1 1 1 1 1 1 1 1 1 1 2 2 2 2 2 2 2 2

⚔️ Extra Challenge ⚔️
Can you adjust your program slightly to sort a list of numbers ranging from 0 up to some arbitrary number n, where n < 256?
*/
int main(){

    //variables
    int arr[256] = {0};
    string str;
    stringstream ss;


    //inputting numbers
    getline(cin, str);
    ss << str;

    int temp;
    while(ss.good()){
        ss >> temp;
        arr[temp]++;
    }

    for(int i=0; i<256; i++){
        for(int j=0; j<arr[i]; j++){
            cout << i << ' ';
        }
    }
    cout << endl;
    return 0;
}