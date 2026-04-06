#include <iostream>
#include <string>

using namespace std;

/*
New Meme

Alien Zorg has created a new meme that is taking the intergalactic community by storm. 
It consists only of a two-digit number usually accompanied by a funny hand gesture. In fact, 
Zorg's fellow aliens are so obsessed that all they hear is the meme! If they hear a string of digits, 
they will just count how many times they can make unique copies of the meme from the string, 
without rearranging the string and only removing digits.

For example, if the meme is "98", and somebody tells them "911287", they will hear the meme once. 
If the string is "998", they will hear the meme "98" twice, since you can make two 98s: 
one from the first nine and the eight, and one from the second nine and the same eight. 
On the other hand, "89" will result in the meme being heard zero times, since you can't change the order of the digits.

Write a program to identify how many times Zorg's meme appears in a given string of digits in O(n) time.
*/
int main(){
    string line;
    getline(cin, line);
    char front = line.at(0), back = line.at(1);
    int frontCount = 0, sum = 0;
    for(int i = 3; i < line.length(); i++){
        char c = line.at(i);
        if(c == back){sum += frontCount;}
        if(c == front){frontCount++;}
    }
    cout << sum << endl;
    return 0;
}