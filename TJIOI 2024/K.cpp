#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){

    //input
    int t;
    string temp;
    cin >> t;
    getline(cin, temp);

    int out[t];
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        getline(cin, temp);

        int k = 1;
        int last = INT_LEAST32_MAX;
        int a;
        for(int j = 0; j < n; j++){
            cin >> a;
            if(a>=last){k++;}
            last=a;
        }
        getline(cin, temp);

        out[i] = k;
    }

    for(int i = 0; i < t; i++){
        cout << out[i] << endl;
    }


    return 0;
}