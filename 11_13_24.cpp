#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    string temp; 

    vector<pair<char,int>> name = vector<pair<char,int>>();
    vector<pair<char,int>> typed = vector<pair<char,int>>();

    getline(cin, temp);
    char latest = (char)0;
    vector<pair<char,int>>* typing = &name;
    for(int i=0; i<temp.size(); i++){
        char current = temp.at(i);
        if(current == ' '){
            if(typing == &name){typing = &typed;}
            else{break;}
        }
        else{
            if(current==latest){
                typing->back().second++;
            }
            else{
                latest = current;
                typing->emplace_back(latest, 1);
            }
        }
    }
    if(name.size() != typed.size()){cout << "false" << endl; return 0;}
    int size = name.size();

    for(int i=0; i<size; i++){
        if(name.at(i).first != typed.at(i).first || name.at(i).second > typed.at(i).second){cout << "false" << endl; return 0;}
    }
    cout << "true" << endl;
    return 0;
}