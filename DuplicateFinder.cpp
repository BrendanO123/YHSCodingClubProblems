#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

/*
First Grade Essays

First graders write essays that are quite repetitive. 
As a 1st grade teacher, you want to know what % of an essay is repeated words so you can give them a more informed grade.

A "repeated word" is defined as an occurrence of a word that has already been used before.

Example input:

The cat ran and ran, faster and faster, down the street.

Output:

36.36%

Example 2:

She looked at the sky and looked at the clouds, wondering and wondering what they meant.

31.25%
*/

int main(){
    unordered_set<string> words = unordered_set<string>();
    vector<char> word = vector<char>();

    string sentence; getline(cin, sentence);
    int wordCount = 0, dupeCount = 0;

    for(char i : sentence){
        word.push_back(tolower(i));
        if(i == ' ' || i == ',' || i == '.' || i == ';' || i == ':' || i == '?' || i == '!' || i == '\'' || i == '\"' || i == '`'){

            word.pop_back();
            word.shrink_to_fit();
            if(word.size() == 0){continue;}

            wordCount++;
            
            if(words.find((string(word.data()))) == words.end()){words.emplace(string(word.data()));}
            else{dupeCount++;}

            word.clear();
        }
    }
    std :: cout << (100 * dupeCount/(float)wordCount) << "%" << std :: endl;
}