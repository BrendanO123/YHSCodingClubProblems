#include <iostream>
#include <string>
#include <sstream>

using namespace std;

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