#include <iostream>
#include <string>
#include <numeric>

using namespace std;

const unsigned int M = 998244353U;
#define checkSolution true

int main(){

    //input
    int n, m;
    cin >> n >> m;

    string temp;
    getline(cin, temp);

        //initial vars
    int mPrime = m+1;
    int g = std :: gcd(mPrime, n); //requires c++17

    int a[n];
    for(int i=0; i<n; i++){cin >> a[i];}

    //data could change to be allocated on heap
    unsigned int CS[n]; //cumulative sum from free variable/start of cycle to n

    //main math
    for(int i=0; i<g; i++){
        CS[i]=0;

        int current =i, next = i+mPrime;
        while(next!=i){
            CS[next]=(a[next]-a[(next-1+n)%n]+CS[current]+M)%M;

            current = next;
            next+=mPrime;
            next%=n;
        }

        if((CS[current]+a[i]-a[(i-1+n)%n]+M)%M){cout << "NO" << endl; return 0;}
    }

    cout << "YES" << endl;

    //making list of +C for equations
    unsigned int C[g];
    for(int i=0; i<g; i++){C[i]=0;}

    //solving for one +C because information was lost in simplification during setup
    int sum=0;
    for(int i=0; i<=m; i++){sum+=CS[i];}
    C[m%g]=(g*(a[m]-sum)/mPrime+M)%M;


    //output
    for(int i=0; i<n; i++){cout << ((CS[i] + C[i%g]+M)%M) << ' ';}
    cout << endl;
    
    //STOP HERE FOR MAX TIME EFFICIENCY AND CORRECT OUTPUT FORMATING
    if(!checkSolution){return 0;}

    //verifying solution
    int lock[n];
    int turns[n];
    for(int i=0; i<n; i++){turns[i] = ((CS[i] + C[i%g]+M)%M); lock[i]=0;}

    for(int i=0; i<n; i++){
        for(int j=i; j<=i+m; j++){
            lock[j%n]+=turns[i];
        }
    }
    for(int i=0; i<n; i++){
        cout << lock[i] << ' ';
        if(lock[i]!=a[i]){cout << "INCORRECT SOLUTION" << endl; return 0;}
    }
    cout << "CORRECT SOLUTION" << endl;

    return 0;
}
