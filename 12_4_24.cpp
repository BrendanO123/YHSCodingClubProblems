#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

struct element{
    vector<char> word = vector<char>();
    bool found;
    int index;

    element(vector<char> name) : found(false), index(0) {word.reserve(name.size()); for(int i=0; i<name.size(); i++){word.push_back(name.at(i));}}

    void compare(char e){
        if(!found){
            if(word.at(index)==e){index++;}
            else{index=0;}
            if(index==word.size()){found=true;}
        }
    }
};
int main(){
    vector<char> arr = vector<char>();
    vector<element> targets = vector<element>();
    string words;
    getline(cin, words);

    for(int i=0; i<words.size(); i++){
        if(words.at(i) == ','){
            if(arr.size()){
                targets.emplace_back(arr);
                arr.clear();
            }
        }
        else{
            arr.push_back(words.at(i));
        }
    }

    if(arr.size()){
        targets.emplace_back(arr);
        arr.clear();
    }

    string search;
    getline(cin, search);

    for(int i=0; i<search.size(); i++){
        for(int j=0; j<targets.size(); j++){targets.at(j).compare(search.at(i));}
    }
    
    for(element e : targets){if(!e.found){cout << "False" << endl; return 0;}}
    cout << "True" << endl;
    return 0;
}