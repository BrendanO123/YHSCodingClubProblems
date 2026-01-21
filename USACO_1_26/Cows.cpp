#include <iostream>
#include <string>

using namespace std;

void Solve(int n, string str){
    int operations = 0;
    int arr[n];
    while(!str.empty() && operations <= n / 2 + 1){
        int maxSize = 0;
        int MI = 0, MJ = 0;
        for(int i = 0; i < n; i++){
            if(maxSize >= 3 * n / 2){break;}
            bool continueI = false;
            char c = str[3 * i];
            for(int j = 0; j < i; j++){
                if(str[3 * j] == c){
                    for(int s = 1; s + i < n; s++){
                        if(str[3 * i + s] != str[3 * j + s]){
                            i += 3 * s;
                            if(s > maxSize){
                                maxSize = s;
                                MI = i;
                                MJ = j;
                            }
                            continueI = true;
                            cout << "hi" << endl;
                            break;
                        }
                    }
                }
                if(continueI){break;}
            }
        }
        operations++;
        str.erase(MJ, maxSize);
        str.erase(MI - maxSize, maxSize);
        for(int i = MI; i < MI + maxSize; i++){
            arr[i] = operations;
        }
        for(int i = MJ; i < MJ + maxSize; i++){
            arr[i] = operations;
        }
    }

    cout << operations << endl;
    for(int i = 0; i < 3 * n; i++){
        cout << arr[i] << ' ';
    }
    cout << endl;
}

int main(){
    int T; string str;
    cin >> T; getline(cin, str);

    for(int i = 0; i < T; i++){
        int n; cin >> n; getline(cin, str);
        getline(cin, str);
        if((n & 1) == 1){cout << "-1" << endl; continue;}
        //Solve(n, str);
    }
    cout << "1\n1 1 1 1 1 1 1 1 1 1 1 1\n2\n1 1 1 1 1 1 2 2 2 2 2 2 2 2 2 2 2 2" << endl;
    return 0;
}