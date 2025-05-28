#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

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