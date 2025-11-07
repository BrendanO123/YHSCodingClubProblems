#include <iostream>
#include <string>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <stack>

using namespace std;

/*
Forest (From TJIOI 2025)

Cookie Monster has a forest of 𝑛 nodes and 𝑚 edges. He wants to add 𝑛−𝑚−1 edges to the forest to create a tree rooted 
at node 1. What is the maximum possible height (the maximum number of edges on a path from the root, node 1, 
to any other node) of this tree?

📃 Input Format
The first line of input contains two integers 𝑛 (1 ≤ 𝑛≤ 2⋅10^5) and 𝑚 (0 ≤ 𝑚 ≤ 𝑛−1).
The next 𝑚 lines each contain two integers 𝑢 and 𝑣 (1 ≤ 𝑢,𝑣 ≤ 𝑛), indicating there is an edge connecting nodes 𝑢 and 𝑣. 
It is guaranteed that the graph contains no self-edges or cycles, and no edge appears multiple times.

📝 Output Format
Output a single integer, the maximum height that Cookie Monster can achieve over all possible resulting trees.
*/
struct Node{
    int dist = 0;
    unordered_set<int> next = unordered_set<int>();

    Node(){}
};
struct Forest{
    unordered_map<int, Node*> nodes = unordered_map<int, Node*>();

    Forest(){}
    ~Forest(){
        for(auto iter = nodes.begin(); iter != nodes.end();){
            delete iter->second;
            iter = nodes.erase(iter);
        }
    }

    inline Node* tryEmplace(int index){
        if(nodes.find(index) == nodes.end()){
            nodes.emplace(index, new Node());
        }
        return nodes.at(index);
    }
    void appendConnection(int n1, int n2){
        auto Node1 = tryEmplace(n1);
        auto Node2 = tryEmplace(n2);

        Node1->next.emplace(n2);
        Node2->next.emplace(n1);
    }

    inline Node* at(int index){
        if(nodes.find(index) == nodes.end()){return nullptr;}
        return nodes.at(index);
    }
};


pair<int, int> DFS(Forest& forest, unordered_set<int>& covered, int naiveRootIndex){
    Node* naiveRoot = forest.at(naiveRootIndex);
    naiveRoot->dist=0;

    stack<int> nodes = stack<int>();
    nodes.emplace(naiveRootIndex);

    int maxDistIndex = naiveRootIndex;
    int maxDist = 0;
    while(!nodes.empty()){
        int index = nodes.top(); nodes.pop();
        if(covered.find(index) != covered.end()){continue;}

        covered.emplace(index);
        auto node = forest.at(index);
        int dist = node->dist+1;
        for(auto iter = node->next.begin(); iter != node->next.end(); iter++){
            int e = *iter;
            if(covered.find(e) != covered.end()){continue;}

            forest.at(e)->dist = dist;
            if(dist > maxDist){maxDist = dist; maxDistIndex = e;}
            if(forest.at(e)->next.size() > 1){nodes.push(e);}
        }
    }
    return pair<int, int>(maxDistIndex, maxDist);
}
int treeLength(Forest& forest, unordered_set<int>& covered, int naiveRootIndex){
    unordered_set<int> coveredTemp = unordered_set<int>();
    auto e = DFS(forest, coveredTemp, naiveRootIndex);
    return DFS(forest, covered, e.first).second;
}

int main(){
    // input
    string temp;
    int n, m;
    cin >> n >> m; getline(cin, temp);

    int dist = n - m - 1;
    auto forest = Forest();

    int n1, n2;
    for(int i=0; i < m; i++){
        cin >> n1 >> n2; getline(cin, temp);
        forest.appendConnection(n1, n2);
    }

    // length summation
    auto covered = unordered_set<int>();
    dist += DFS(forest, covered, 1).second;
    for(int i=2; i <= n; i++){
        if(covered.find(i) != covered.end()){continue;}

        auto node = forest.at(i);
        if(node == nullptr){continue;}
        dist += treeLength(forest, covered, i);
    }

    cout << dist << endl;
    return 0;
}