#include <iostream>
#include <string>
#include <stack>

using namespace std;

/*
Valid Parentheses

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/
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

    if(bracketStack.size()){cout << "false" << endl; return 0;} // unclosed bracket
    cout << "true" << endl;
    return 0;
}