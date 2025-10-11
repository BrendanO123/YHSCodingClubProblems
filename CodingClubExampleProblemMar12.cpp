#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main(){
    string str;
    std :: cout << "Enter a Pig Latin String:" << std :: endl;
    getline(cin, str);
    char* chars = str.data(); int size = str.size();
    char sentenceDelim = '.', wordDelim = ' ';
    vector<string> words = vector<string>();
    vector<char> word = vector<char>();
    
    bool capitalized = false;
    bool newSentence = false;
    for(int i=0; i<=size; i++){
        if(i != size && chars[i] == sentenceDelim){
            newSentence = true; 
        }
        else if(i == size || chars[i] == wordDelim){
            if(word.empty()){continue;}
            if(isupper(word[0])){
                capitalized = true; word[0] = tolower(word[0]);
            }
            for(int i = word.size()-2; i>0; i--){
                word[i] = word[i-1];
            }
            word.at(0) = (capitalized ? toupper(word.at(word.size()-2)) : tolower(word.at(word.size()-2)));
            word.pop_back(); word.pop_back(); word.shrink_to_fit(); 
            if(newSentence){word.push_back('.'); capitalized = true;}
            else{capitalized = false;}

            newSentence = false;
            words.push_back(string(word.data()));
            word.clear();
        }
        else{
            word.emplace_back(chars[i]);
        }
    }

    for(int i = 0; i<words.size(); i++){std :: cout << words.at(i) << ' ';}

    return 0;
}