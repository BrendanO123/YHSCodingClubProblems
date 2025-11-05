#include <iostream> 
#include <string>

#define M 998244353 // big prime number

using namespace std;

/*
Given a binary string A consisting of only ones and zeros and a number N, 
output the number of binary strings B where B has the same length as A, B > A*, 
and B contains exactly N ones and (length)-N zeros. Because this answer may be very large, 
print the number modulo 998,244,353.

*B > A if and only if the first digit that differs between A & B is a one in B and a zero in A. For example:
A = 10010110
B = 10011000

Hint: the number of strings with length L containing N ones is equal to:
L! / ((L - N)! * N!) = 
((L - N - 1) * (L - N) * (L - N + 1) * … * (L - 2) * (L - 1) * L) / (1 * 2 * 3 * … * (N - 2) * (N - 1) * N)

Input:
Each test contains multiple test cases. The first line contains the number of test cases T.
The first line of each test case contains the length of the string L and the positive integer N. 
The second line of each test case contains the string A with length L.

Output:
For each test case, output an integer on a new line, the number of binary strings that satisfy the 
conditions modulo 998,244,353.
*/
int moduloNCR(int n, int k){
    if(k < 0 || k > n){return 0;} // if k < 0 or n - k < 0 return invalid

    int product = 1;
    if(k > n-k){k = n-k;} // find min number of steps by using nCr(n, k) = nCr(n, n-k)
    for(int i = 1; i <= k; i++){ // calculate nCr with minimal overflows
        product *= n - k + i; // product *= n!/((n-k)!)
        product /= i; // product /= k!
    }
    product %= M; // once done, modulo by M

    return product;
}

int main(){
    string line;
    int t;
    cin >> t; getline(cin, line);

    int sums[t]; // keep track of answers in array and print at the end so prints don't overlap with input
    for(int j=0; j<t; j++){
        int l, n;
        cin >> l >> n; getline(cin, line);
        getline(cin, line);

        sums[j]=0;
        for(int i=0; i<l; i++){
            if(n > l-i || n <= 0){break;} // if remaining ones > remaining digits (including current) or remaining ones is zero: break;
            if(line.at(i) == '1'){n--;} // keep track of ones remaining
            else{
                sums[j] += moduloNCR(l-i-1, n-1); // every time we encounter a zero, we can create larger strings than A
                // therefore, we increase the sum by the number of strings we can make 
                // if we place a one instead of this zero, we have l-i-1 digits left to play with
                // and n - 1 ones left to place, therefore sum += nCr(l - i - 1, n - 1);
                sums[j] %= M;
            }
        }
    }
    for(int sum : sums){cout << sum << endl;} // print outputs once input is done
    return 0;
}