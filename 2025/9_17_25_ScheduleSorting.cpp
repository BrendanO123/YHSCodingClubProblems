#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <regex>

using namespace std;

/*
Schedule Sorting

A disgruntled ex has stolen your school schedule, and refuses to give it to you except in the form of cryptic clues. 
These clues come in the form of "X before Y" (as in, "Physics before Math"). 
Create a program that takes a list of these clues and outputs the correct order of your classes.

Additionally, your ex is kind of stupid, and might be doing the clues wrong. 
Your program needs to detect an "impossible" schedule layout: for example, having the clues 
"Physics before Math", "Math before History", and "History before Physics" would result in an output 
of "impossible", since if physics is before math, then it has to be before history, which is before physics,
but physics is already before math, so it simply doesn't work.

📃 Input Format

<number of clues>
X before Y
Y before Z
...

📝 Output Format

X
Y
Z
*/
int main(){

    //vars
    unordered_map<string, pair<int, unordered_set<string>>> graph = unordered_map<string, pair<int, unordered_set<string>>>();
    unordered_set<string> firstClassCandidates = unordered_set<string>();

    //input
    int clueCount; //get int clue count
    string line, first, second;
    cin >> clueCount;
    getline(cin, line);

    sregex_token_iterator end; //vars for unnecessarily overcomplicated way to break into first and second classes
    regex pattern = regex("\\s+before\\s+");
    for(int i=0; i < clueCount; i++){
        getline(cin, line); //get clue

        //unnecessarily overcomplicated way to break into first and second classes
        auto iter = sregex_token_iterator(line.begin(), line.end(), pattern, -1);
        first = iter->str(); iter++;
        second = iter->str();

        // if first class is new, add to graph and mark as candidate for first class
        if(graph.find(first) == graph.end()){
            graph.emplace(first, pair<int, unordered_set<string>>(0, unordered_set<string>()));
            graph.at(first).second.emplace(second);
            firstClassCandidates.emplace(first);
        }
        else{
            // if existing, add class it is before to its list of classes it is before
            if(graph.at(first).second.find(second) == graph.at(first).second.end()){
                graph.at(first).second.emplace(second);
            }
        }

        // remove the class it is before from the candidates for the first class 
        if(firstClassCandidates.find(second) != firstClassCandidates.end()){firstClassCandidates.erase(second);}

        // if the class it is before is new, add that to the graph as well
        if(graph.find(second) == graph.end()){
            graph.emplace(second, pair<int, unordered_set<string>>(0, unordered_set<string>()));
        }
    }

    // if there is 0 or more than 1 first class, it is not possible
    if(firstClassCandidates.size() != 1){cout << "impossible" << endl; return 0;} 


    //analysis
    string firstClass = *firstClassCandidates.begin(); //vars
    vector<unordered_set<string>> schedule = vector<unordered_set<string>>(graph.size());
    schedule.at(0).emplace(firstClass); 
        // schedule contains a set of all classes that may be at any given period
        // by the end of the analysis this needs to drop to one class per period
        // in the middle though, many classes will think they are in the same period until their index is updated


    // BFS queue
    queue<string> BFSQueue = queue<string>();
    BFSQueue.emplace(firstClass);

    // BFS through graph to set the index of every node to the maximum number of steps it is from the start
    while(!BFSQueue.empty()){

        //get next and ensure protection from out of bounds 
        //  (out of bounds means we have walked in a loop bc we have taken more steps than we have classes)
        auto current = graph.at(BFSQueue.front());
        int next = current.first + 1;
        if(next < 1 || (current.second.size() > 0 && next >= graph.size())){cout << "impossible" << endl; return 0;}
        BFSQueue.pop();

        // look at classes it is before and check out of bounds again
        for(auto e = current.second.begin(); e != current.second.end(); e++){
            int nextNodeIndex = graph.at(*e).first;
            if(nextNodeIndex < 0 || nextNodeIndex >= graph.size()){cout << "impossible" << endl; return 0;}

            // if we have found a longer path to the node, update it and push to BFS queue
            if(graph.at(*e).first < next){

                // if it is already in the schedule at the old period, delete it
                if(schedule.at(nextNodeIndex).find(*e) != schedule.at(nextNodeIndex).end()){
                    schedule.at(nextNodeIndex).erase(*e);
                }
                
                // update the node and push to queue 
                graph.at(*e).first = next;
                BFSQueue.push(*e);

                // place it in a new period in the schedule
                if(schedule.at(next).find(*e) == schedule.at(next).end()){
                    schedule.at(next).emplace(*e);
                }

            }
        }
    }

    // print schedule or print impossible if there is 0 or more than 1 classes in any given period
    for(unordered_set<string> e : schedule){
        if(e.size() != 1){cout << "impossible" << endl; return 0;}
        cout << *e.begin() << endl;
    }

    return 0;
}