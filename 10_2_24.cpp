#include <iostream>
#include <string>

using namespace std;

int main(){
    int n1; string temp;
    int n2;

    cin >> n1;
    getline(cin, temp);

    char deck1[n1];
    for(int i=0; i<n1; i++){deck1[i]=temp.at(i+1);}


    cin >> n2;
    getline(cin, temp);

    char deck2[n2];
    for(int i=0; i<n2; i++){deck2[i]=temp.at(i+1);}


    int max = (n1 >= n2 ? n1 : n2);
    for(int i=0; i<max; i++){
        if(i<n1){cout << deck1[i];}
        if(i<n2){cout << deck2[i];}
    }
    cout << endl;

    return 0;
}