#include <iostream>
#include <string>
#include <stack>
#include <regex>

using namespace std;

int main(){

    //vars
    stack<char> bracketStack = stack<char>();
    string line;

    //input
    getline(cin, line);

    for(char c : line){
        switch(c){
            case '(':
                bracketStack.push('(');
                break;
            case '{':
                bracketStack.push('{');
                break;
            case '[':
                bracketStack.push('[');
                break;
            case ')':
                if(bracketStack.size()<1){cout << "false" << endl; return 0;}
                if(bracketStack.top()!='('){cout << "false" << endl; return 0;}
                bracketStack.pop();
                break;
            case ']':
                if(bracketStack.size()<1){cout << "false" << endl; return 0;}
                if(bracketStack.top()!='['){cout << "false" << endl; return 0;}
                bracketStack.pop();
                break;
            case '}':
                if(bracketStack.size()<1){cout << "false" << endl; return 0;}
                if(bracketStack.top()!='{'){cout << "false" << endl; return 0;}
                bracketStack.pop();
                break;
        }
    }

    if(bracketStack.size()){cout << "false" << endl; return 0;}
    cout << "true" << endl;
    return 0;
}