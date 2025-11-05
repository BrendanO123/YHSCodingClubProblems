#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

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
    unordered_map<char, char> bracketTypes = unordered_map<char, char>({
        {'(', ')'}, 
        {'[', ']'}, 
        {'{', '}'}
    });

    //input
    getline(cin, line);

    //analysis
    for(char c : line){
        if(bracketTypes.find(c) != bracketTypes.end()){bracketStack.push(c);} // push open grouping to stack
        else if(bracketStack.size()<1){cout << "false" << endl; return 0;} // if closed grouping, ensure we have a grouping to close
        else{
            if(bracketTypes.at(bracketStack.top()) != c){cout << "false" << endl; return 0;} // ensure matches last opened grouping
            bracketStack.pop(); // close grouping
        }
    }

    if(bracketStack.size()){cout << "false" << endl; return 0;} // unclosed brackets remain in stack
    cout << "true" << endl;
    return 0;
}