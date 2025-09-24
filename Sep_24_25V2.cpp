#include <iostream>
#include <string>
#include <stack>
#include <unordered_map>

using namespace std;

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