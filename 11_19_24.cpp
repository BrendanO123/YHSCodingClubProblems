#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <sstream>

using namespace std;

int main(){
    int temp;
    string str;

    stringstream ss;
    getline(cin, str);
    for(int i=0; i<str.size(); i++){if(str.at(i) == ','){str.at(i)=' ';}}
    ss<<str;

    vector<int> arr = vector<int>();
    while(ss.good()){
        ss>>temp;
        arr.push_back(temp);
    }
    int size = arr.size()-1;

    int diff[size];
    for(int i=0; i<size; i++){diff[i]=arr.at(i+1)-arr.at(i);}

    int CS=0;
    int max = INT_LEAST32_MIN;
    bool pos=false;
    for(int i=0; i<size; i++){
        CS += diff[i];
        if(CS<0){CS=0;}
        if(CS>max){max=CS;}
    }
    cout << max << endl;

    return 0;
}