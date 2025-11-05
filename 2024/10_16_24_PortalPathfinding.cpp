#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>

using namespace std;

/*
Portal Pathfinding

Given a list of portal starting and ending points, output if the path is possible.

A portal is given as a letter followed by a comma-separated list of letters representing the portals it can go to.
You'll be given a list of portals, with the final line being the comma-separated start and end portals.
*/
struct Node{
    bool visited;
    queue<char> out;
    int exits;

    Node() : visited(false), exits(0){out = queue<char>();}
};
int main(){
    unordered_map<char, Node> nodes = unordered_map<char, Node>();
    string temp;

    getline(cin, temp);
    char first, last;
    while(!temp.empty()){
        if(temp.at(1) == ','){
            first = temp.at(0);
            last = temp.at(2);
            break;
        }
        else{
            char letter = temp.at(0);
            nodes.emplace(letter, Node());
            for(int i=3; i<temp.size(); i+=2){
                nodes.at(letter).out.push(temp.at(i));
                nodes.at(letter).exits++;
            }
        }
        getline(cin, temp);
    }
    queue<char> stack = queue<char>();
    stack.push(first);

    while(!stack.empty()){
        char id = stack.front();
        stack.pop();
        if(id==last){cout << "True" << endl; return 0;}
        if(nodes.find(id)!=nodes.end()){
            if(!nodes.at(id).visited){
                nodes.at(id).visited=true;
                queue<char> next = nodes.at(id).out;
                while(!next.empty()){
                    stack.push(next.front());
                    next.pop();
                }
            }
        }
    }
    cout << "False" << endl;

    return 0;
}