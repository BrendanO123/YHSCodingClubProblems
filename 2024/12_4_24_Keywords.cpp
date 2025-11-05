#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

/*
Keywords

You are given a list of keywords and a sentence. Output True if the sentence contains all of the keywords, 
and False otherwise. The sentence may contain other words not in the list of keywords.

The first line of your input will be the list of keywords, separated by commas. The second line will be the sentence, 
consisting of only lowercase letters and spaces. Do not assume that the words in the sentence are separated by spaces.

CHALLENGE: Determine the time complexity of your solution, where k=keyword count and n=length of the sentence. 
Can you solve this problem in O(n) time complexity?
*/
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