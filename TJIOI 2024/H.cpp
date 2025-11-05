#include <iostream>
#include <unordered_map>
#include <string>
#include <limits>

using namespace std;

/*
Cookie Monster’s favorite word can be represented as a string B. He currently has a string A and wants
to use it to create as many copies of string B as possible.
To do this, Cookie Monster will first rearrange the characters in A however he likes. Then, he will do the
following: while string B is a prefix of A, keep removing that prefix. What is the maximum number of
times he can remove the string B from A if he arranges the characters of A optimally?

Input
The first line of input contains the string A. The second line of input contains the string B.
(1 ≤ |A|, |B| ≤ 105), where |A| indicates the length of string A. Strings A and B only contain lowercase
alphabet characters.

Output
The maximum number of times Cookie Monster can remove string B from string A as a prefix.
*/
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