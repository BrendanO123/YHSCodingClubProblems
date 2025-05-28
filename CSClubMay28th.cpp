#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){

    //variables
    vector<unsigned char> arr = vector<unsigned char>();
    string str;
    stringstream ss;


    //inputting numbers
    getline(cin, str);
    ss << str;

    int temp;
    while(ss.good()){
        ss >> temp;
        arr.push_back(temp);
    }

    //sort and exit
    sort(arr.begin(), arr.end());

    for(int i : arr){cout << i << ' ';}
    cout << endl;
    return 0;
}