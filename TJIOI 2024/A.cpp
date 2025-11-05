#include <iostream>
#include <string>

using namespace std;

/*
Cookie Monster and Elmo are playing a game where they each take turns eating cookies. They have c
cookies in total. On a player’s turn, they can either eat a single cookie, or eat half of the remaining cookies.
If the remaining cookies happens to be odd, eating half of the cookies is equivalent to eating (c+1)/2 cookies.
Cookie Monster goes first and the game ends when there are no cookies left. The person who eats the last
cookie wins. Output who wins.

Input
The first line contains c (1 ≤ c ≤ 1018) — the number of cookies.

Output
Output Cookie Monster if Cookie Monster wins. Otherwise output Elmo.
*/
int main(){

    //input
    unsigned long n;
    cin >> n;
    if((__builtin_ctz(n) & 1) == 0){
        cout << "Cookie Monster" << endl;
    }
    else{
        cout << "Elmo" << endl;
    }

    return 0;
}
