#include <iostream>
#include <string>
#include <numeric>

using namespace std;

const unsigned int M = 998244353U;
int main(){
    int n, m;
    cin >> n >> m;

    string temp;
    getline(cin, temp);

    int mPrime = m+1;
    int g = std :: gcd(mPrime, n);

    int a[n];
    for(int i=0; i<n; i++){cin >> a[i];}

    unsigned int CS[n]; //cumulative sum from free variable/start of cycle to n
    int FV[n]; //free variable giving a +C to turns at n/start of cycle containing n

    for(int i=0; i<g; i++){
        FV[i]=i; CS[i]=0;

        int current =i, next = i+mPrime;
        while(next!=i){
            FV[next]=i;
            CS[next]=(a[next]-a[(next-1+n)%n]+CS[current]+M)%M;

            current = next;
            next+=mPrime;
            next%=n;
        }

        if((CS[current]+a[i]-a[(i-1+n)%n]+M)%M){cout << "NO" << endl; return 0;}
    }

    cout << "YES" << endl;

    int sum=0;
    for(int i=0; i<=m; i++){sum+=CS[i];}

    unsigned int C[g];
    for(int i=0; i<g; i++){C[i]=0;}
    C[FV[m]]=(g*(a[m]-sum)/mPrime+M)%M;

    for(int i=0; i<n; i++){cout << ((CS[i] + C[FV[i]]+M)%M) << ' ';}
    cout << endl;
}