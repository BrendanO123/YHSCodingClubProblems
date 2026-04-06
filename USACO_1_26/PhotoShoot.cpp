#include <iostream>
#include <string>

using namespace std;

int n, k;
inline int getIndex(int x, int y){return x + y * n;}
inline bool isInBounds(int x, int y){return 0 <= x && x < n && 0 <= y && y < n;}

int main(){
    string str;
    cin >> n >> k; getline(cin, str);

    int arr[n * n]; 
    int sums[n * n];
    for(int i = 0; i < n * n; i++){
        arr[i] = 0;
        sums[i] = 0;
    }

    int q; cin >> q;
    int results[q];

    int maxSum = 0;
    for(int i = 0; i < q; i++){
        int r, c, v;
        cin >> r >> c >> v; getline(cin, str);
        r--; c--;

        int previous = arr[getIndex(c, r)];
        arr[getIndex(c, r)] = v;
        int diff = v - previous;

        for(int y = max(0, r - k + 1); y <= r; y++){
            for(int x = max(0, c - k + 1); x <= c; x++){
                if(!isInBounds(x,y)){continue;}
                sums[getIndex(x,y)] += diff;
                if(sums[getIndex(x,y)] > maxSum){maxSum = sums[getIndex(x,y)];}
            }
        }
        results[i] = maxSum;
    }

    for(int i = 0; i < q; i++){
        cout << results[i] << endl;
    }
    return 0;
}