#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    //Input
    string temp; stringstream ss;
    getline(cin, temp); ss << temp;

    vector<int> arr = vector<int>();
    unordered_map<int,int> map = unordered_map<int,int>();

    pair<int,int> solution = pair<int,int>(-1,-1);
    for(int i = 0; !ss.bad() && !ss.eof(); i++){
        int a; ss >> a;
        if(ss.bad()){break;}
        arr.emplace_back(a);
        if(map.find(a) != map.end()){ // the only way for duplicate elements to have exactly one solution is if
                                        // they collectively add to N together. I.E., they are both one half of N
            solution = pair<int,int>(i, map.at(a));
        }
        else{map.emplace(a, i);}
    }
    int n; cin >> n;

    if(solution != pair<int,int>(-1,-1)){
        cout << solution.first << ' ' << solution.second << endl;
        return 0;
    }
    for(int i = 0; i < arr.size(); i++){
        if(map.find(n - arr.at(i)) != map.end()){
            if(i != map.at(n - arr.at(i))){
                cout << i << ' ' << map.at(n - arr.at(i)) << endl;
                return 0;
            }
        }
    }
    return 0;
}