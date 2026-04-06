#include <iostream>
#include <string>

using namespace std;

/*
Simplest Radical Form

Write a program that, given a number, outputs the simplest radical form of that number. 
For example, the simplest radical form of 12 is 2√3, and the simplest radical form of 18 is 3√2.

The formal definition of simplest radical form is as follows: 
A number is in simplest radical form if it is of the form a√b, where a and b are positive integers, 
and b is not divisible by any perfect square other than 1.

Input Format
An integer.

Output Format
The simplest radical form of the input number, in the format a√b. If the input number is a perfect square, output just a√1, where a is the square root of the input number. If the input number cannot be simplified, output 1√a, where a is the input number.
*/

int main(){
    int n; cin >> n;
    int m = 1;
    string rad = "√";
    for(int i = 2; i <= n; i++){
        int count = 0;
        while(n % i == 0){
            n /= i;
            count++;
        }
        if((count & 1) == 1){n *= i; count--;}
        count /= 2;
        for(int j = 0; j < count; j++){m *= i;}
    }
    cout << m << rad << n << endl;
    return 0;
}