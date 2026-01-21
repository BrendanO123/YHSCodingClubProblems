#include <string>
#include <iostream>

using namespace std;

int main(){
    int T;
    string temp;
    cin >> T;
    getline(cin, temp);

    long long arr[T];
    for(int i = 0; i < T; i++){
        long long A, B, CA, CB, FA;
        cin >> A >> B >> CA >> CB >> FA;
        getline(cin, temp);

        long long x = (FA - A - (B / CB) * CA - 1LL);
        arr[i] =
                1LL + (CB - 1LL - (B % CB)) + max(
                x % CA + (x / CA) * CB, 
                x
            );
        if(x < 0LL || arr[i] <= 0LL){arr[i] = 0LL;}
    }

    for(int i = 0; i < T; i++){
        cout << arr[i] << endl;
    }

    return 0;
}