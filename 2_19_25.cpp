#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main(){
    string temp;
    int x, y;
    pair<int, int> origin;
    pair<int, int> delta;

    stringstream ss;
    getline(cin, temp);
    for(int i=0; i<temp.size(); i++){if(temp.at(i) == ','){temp.at(i)=' ';}}
    ss<<temp;

    ss >> x >> y;
    origin = pair<int, int>(x,y);
    
    ss >> x >> y;
    delta = pair<int, int>(x-origin.first, y-origin.second);


    while(!ss.eof() && !ss.bad()){
        ss >> x >> y;
        pair<int, int> point = pair<int, int>(x-origin.first, y-origin.second);
        if(float(point.first)/delta.first * delta.second != point.second){cout << "false" << endl; return 0;}
    }
    cout << "true" << endl;
    
    return 0;
}