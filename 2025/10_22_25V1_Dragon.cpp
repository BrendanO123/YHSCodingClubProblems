#include <iostream>
#include <string>
#include <limits>

using namespace std;

/*
Stealing From A Dragon

You and your friends, bored during a 3-day weekend, have decided to steal gold from a dragon. 
This dragon has OCD, and all of his treasure chests are in a row. However, he won't notice if you take a 
consecutive chunk of K chests...

There are N treasure chests in a row, chest i has a[i] gold coins (yes, some chests are cursed and have negative "gold"). 
You must pick exactly K consecutive chests to grab. Find the maximum gold you can steal in one raid.

📃 Input Format

N K
a1 a2 ... aN

📝 Output Format

A single integer, the maximum amount of gold you can steal.
*/
int main(){
    string temp;
    int n, k;
    cin >> n >> k; getline(cin, temp);

    int max = INT32_MIN;
    int cumSum = 0;
    int a;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> a; arr[i] = a;
        cumSum += a;
        if(i + 1 > k){cumSum -= arr[i - k];}
        if(i + 1 >= k && cumSum > max){max = cumSum;}
    }
    cout << max << endl;

    return 0;
}