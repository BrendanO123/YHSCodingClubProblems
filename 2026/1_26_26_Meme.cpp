#include <iostream>
#include <string>

using namespace std;

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