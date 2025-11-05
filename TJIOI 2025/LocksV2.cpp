#include <iostream>
#include <string>
#include <numeric>

using namespace std;

const unsigned int M = 998244353U;
#define checkSolution true //control flow to enable solution checking code

/*
Cookie Monster has an interesting digit combination lock, with each digit being an integer
ranging from [0, 998 244 353). The lock starts out with all zeroes, and it is interesting because the
digits are arranged in a circular fashion. When Cookie Monster goes to rotate one digit, the next m
digits in the clockwise direction also change with it. Help Cookie Monster determine if a specific
combination is reachable from all zeroes and give him a set of steps he can take to achieve it.

Input
The first line contains two space-separated integers n and m (1 <= n <= 2 * 10^5, 0 <= m < n).
The second line consists of n space-separated integers a[1], a[2], ..., a[n] (0 <= a[i] < 998 244 353) which
represent a specific combination.

Output
Output "YES" if Cookie Monster can create the combination or "NO" if he can't. 
Then, if you said "YES", on the next line print n integers c[1], c[2], ..., c[n] each in the range [0, 998 244 353), 
where c[i] corresponds to the number of times Cookie Monster should increase the digit on the i-th lock.
*/
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

    //solving for one +C because information was lost in simplification during setup
    int sum=0;
    for(int i=0; i<=m; i++){sum+=CS[i];}
    CS[m%g]=(g*(a[m]-sum)/mPrime+M)%M;


    //output
    for(int i=0; i<n; i++){cout << ((CS[i] + CS[i%g]+M)%M) << ' ';}
    cout << endl;
    
    //STOP HERE FOR MAX TIME EFFICIENCY AND CORRECT OUTPUT FORMATING
    if(!checkSolution){return 0;}

    //verifying solution
    int lock[n];
    int turns[n];
    for(int i=0; i<n; i++){turns[i] = ((CS[i] + CS[i%g]+M)%M); lock[i]=0;}

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
