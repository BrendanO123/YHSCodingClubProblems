#include <iostream>
#include <string>

using namespace std;

/*
No Laughing Matter

You just told your friend about a serious tragedy you saw in the news. Their response consists of only letters, which, 
given your friend's "dark" sense of humor, probably includes some laughing. 
Laughter is a substring repeated "ha"s in the response. Find the longest substring of laughter in your friend's response.

Input Format
Your friend's response (a string of only lowercase letters).

Output Format
The longest amount of "ha"s in a row in the response.
*/

int main(){
    string line; getline(cin, line);
    int count = 0;
    int max = 0;
    for(int i = 0; i < line.size()-1; i++){
        if(line.at(i) == 'h'){
            if(line.at(i+1) == 'a'){
                count++;
                if(count > max){max = count;}
                i++;
                continue;
            }
        }
        count = 0;
    }
    cout << max << endl;
    return 0;
}