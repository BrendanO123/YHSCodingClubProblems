#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

int main(){

    //input
    string word; 
    string target;
    getline(cin, word);
    getline(cin, target);

    //vars
    const char* wordArr = word.data();
    const char* targetArr = target.data();
    unordered_map<char, pair<int,int>> map = unordered_map<char, pair<int,int>>();

    for(int i = 0; i < target.length(); i++){
        char c = targetArr[i];
        if(map.find(c) == map.end()){
            map.emplace(c, pair<int, int>(0, 1));
        }
        else{
            map.at(c).second++;
        }
    }
    for(int i = 0; i < word.length(); i++){
        char c = wordArr[i];
        if(map.find(c) != map.end()){
            map.at(c).first++;
        }
    }

    int min = INT_LEAST32_MAX;
    auto iterate = map.begin();
    while(iterate != map.end()){
        pair<int, int> p = iterate->second;
        int instances = p.first/p.second;
        if(instances<min){min=instances;}
        iterate++;
    }
    cout << min << endl;

    return 0;
}