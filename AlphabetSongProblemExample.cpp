#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void charProblem(char start, string phrase){
    char max;
    for(char c : phrase){
        if(c<= max){cout << 1 << endl; return;}
        max = c;
    }
    cout << int(start - max) << endl;
}
void intProblem(int start, int length){
    int num;
    int max = -1;
    for(int i = 0; i < length; i++){
        cin >> num;
        if(num <= max){cout << 1 << endl; return;}
        max = num;
    }
    cout << start - max << endl;
}

int main(){
    char c;
    cin >> c;
    if('a' <= c && c <= 'z'){
        string phrase;
        getline(cin, phrase);
        charProblem(c, phrase.substr(1));
        return 0;
    }
    if('0' <= c && c <= '9'){
        string line;
        getline(cin, line);
        stringstream ss;
        ss << c << line;

        int start, length;
        ss >> start >> length;
        intProblem(start, length);
        return 0;
    }
    return -1;
}