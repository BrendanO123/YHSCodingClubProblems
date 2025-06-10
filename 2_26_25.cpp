#include <iostream>
#include <string>
#include <sstream>
#include <bit>

using namespace std;

int main(){
    unsigned int num, div;
    cin >> num; 

    string temp;
    getline(cin, temp);
    stringstream ss;
    
    ss << temp.substr(1); ss >> div;

    unsigned int q = 0;
    unsigned int i = __countl_zero(div);
    unsigned int l = div << i;
    while(l >= div){
        if(l<= num){num-=l; q |=(1<<i);}
        else{l>>=1; i--;}
    }

    cout << num << endl;
    return 0;
}