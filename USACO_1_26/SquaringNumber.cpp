#include <iostream>

using namespace std;

/*
This problem came from a coding competition at Montgomery College, which we won recently. 
This was the last problem of the contest, which we were unable to finish debugging before the time ran out
    (we put < instead of <= by mistake).
The task is: given a natural number M, output the least natural number N such that N * M is a perfect square.
The main way to do this is to break M into its prime factorization and for each prime factor:
    if its degree is odd, it must be a prime factor of N.
Therefore, we simply find the product of each prime factor of M with odd degree.
*/
int main(){
    int m, m2, n = 1;
    cin >> m; m2 = m;
    for(int i = 2; i <= m; i++){
        int count = 0;
        while(m % i == 0){
            m /= i;
            count++;
        }
        if((count & 1) == 1){
            n *= i;
        }
    }
    cout << "N: " << n << endl;
    cout << "Square (n * m): " << m2 * n << endl;
    return 0;
}