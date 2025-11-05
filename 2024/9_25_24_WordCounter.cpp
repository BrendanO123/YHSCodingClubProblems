#include <iostream>
#include <string>

using namespace std;

/*
Word Counter

Create a program that counts the number of words in a string. For example, the string "Hello, world!" has 2 words.

A word is defined as a sequence of _lowercase letters_. Words will be separated by spaces. Note that, 
for example the string: "! !" contains 0 words, because the exclamation mark is not a letter.

Your input will be a string of lowercase letters, spaces, and punctuation (no numbers). The input may have extra 
spaces at the beginning, end, or between words. Your output should be the number of words in the string, 
following the definition of "word" above.
*/
int main(){
    string sentence;
    getline(cin, sentence);
    
    int len = sentence.length();

    bool hasWord = false;
    char e;
    int count = 0;
    for(int i=0; i<len; i++){
        e=sentence.at(i);
        if(('A' <= e && e <= 'Z') || ('a' <= e && e<= 'z')){hasWord=true;}
        if(e == ' '){
            if(hasWord){count++;}
            hasWord=false;
        }
    }
    if(hasWord){count++;}
    cout << count << endl;
    return 0;
}