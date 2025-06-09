#include <iostream>
#include <string>

using namespace std;

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