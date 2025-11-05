#include <iostream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

/*
Your challenge: Write a function that takes a string of pig latin and returns the original English version.

Pig Latin:

Pig Latin is a language game that children use to speak in code. To translate a phrase into pig latin, follow these steps:
1. For each word, move the first letter to the end of the word.
2. Add "ay" to the end of the word.

For example, the word "hello" would become "ellohay".
The word "avacado" would become "vacadoaay".

Challenge Input:

A string of pig latin.
The string will contain multiple sentences in pig latin.
Each sentence is separated by a ```.``` followed by a space.
Some words may have an uppercase first letter.

Challenge Output:

A string of English sentences. Each sentence should be separated by a ```.``` followed by a space.
The first letter in every sentence should be capitalized.
Make sure to maintain capitalization of words with uppercase first letters.
*/
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