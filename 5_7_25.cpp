#include <iostream>
#include <string>

using namespace std;

int main(){
    string temp;
    getline(cin, temp);

    int sum = 0;
    int prod = 1;
    for(int i=temp.size()-1; i>=0; i--){
        sum+=(temp.at(i)-'A'+1) * prod;
        prod*=26;
    }
    cout << sum << endl;
    return 0;
}