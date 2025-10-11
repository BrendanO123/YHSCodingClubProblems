#include <iostream>
#include <unordered_set>
#include <string>
#include <sstream>

using namespace std;

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