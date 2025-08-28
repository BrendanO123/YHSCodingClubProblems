#include <iostream>
#include <string>

using namespace std;

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
