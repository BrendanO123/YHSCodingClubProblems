#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
Best Poker Hand

You are given an integer array `ranks` and a character array `suits`. You have 5 cards where the ith card has a 
rank of ranks[i] and a suit of suits[i]. Ranks are given as a comma separated list on the first line, 
and suits are given comma separated on the second line.

The following are the types of poker hands you can make from best to worst:

1. "Flush": Five cards of the same suit.
2. "Three of a Kind": Three cards of the same rank.
3. "Pair": Two cards of the same rank.
4. "High Card": Any single card.

Return a string representing the best type of poker hand you can make with the given cards.
*/
int main(){
    string temp; int itemp; char ctemp;
    int rankCounts[13] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    int suitCounts[4] = {0, 0, 0, 0};

    stringstream ss;
    getline(cin, temp);
    for(int i=0; i<temp.size(); i++){if(temp.at(i) == ','){temp.at(i)=' ';}}
    ss<<temp;

    for(int i=0; i<5; i++){ss >> itemp; rankCounts[itemp-1]++;}
    ss.clear();

    getline(cin, temp);
    for(int i=0; i<9; i+=2){suitCounts[int(temp.at(i)-'a')]++;}

    for(int i=0; i<4; i++){if(suitCounts[i]==5){cout << "Flush" << endl; return 0;}}
    for(int i=0; i<13; i++){if(rankCounts[i]>=3){cout << "Three of a Kind" << endl; return 0;}}
    for(int i=0; i<13; i++){if(rankCounts[i]==2){cout << "Pair" << endl; return 0;}}
    cout << "High Card" << endl;

    return 0;
}