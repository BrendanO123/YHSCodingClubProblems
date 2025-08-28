#include <iostream>

using namespace std;

int main(){

    //input
    int n, m, c;
    cin >> n >> m >> c;

    int R = c % (n+m);
    if(R == 0 || R > n){
        cout << "Elmo" << endl;
    }
    else{
        cout << "Cookie Monster" << endl;
    }

    return 0;
}
