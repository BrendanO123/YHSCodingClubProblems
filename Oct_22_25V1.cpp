#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main(){
    string temp;
    int n, k;
    cin >> n >> k; getline(cin, temp);

    int max = INT32_MIN;
    int cumSum = 0;
    int a;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> a; arr[i] = a;
        cumSum += a;
        if(i + 1 > k){cumSum -= arr[i - k];}
        if(i + 1 >= k && cumSum > max){max = cumSum;}
    }
    cout << max << endl;

    return 0;
}