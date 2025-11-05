#include <iostream>
#include <string>

using namespace std;

/*
Challenge #54: Excel Sheet Column Numbers 🔢

Given a string that represents the column title as appears in an Excel sheet, print its corresponding column number.

The pattern:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
*/
int main(){
    string temp;
    getline(cin, temp);

    int sum = 0;
    int prod = 1;
    for(int i=temp.size()-1; i>=0; i--){
        sum+=(temp.at(i)-'A'+1) * prod;
        prod*=26;
    }
    cout << sum << endl;
    return 0;
}