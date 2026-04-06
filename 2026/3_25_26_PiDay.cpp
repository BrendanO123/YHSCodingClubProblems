#include <iostream>

using namespace std;

/*
Belated Pi Day

While quite a bit late to Pi day, we should still celebrate. Recently, 
a paper was released that shows you can approximate π (specifically, π/4) just by flipping a coin many, many times.

Write a program that approximates π by using the method described in the paper: https://arxiv.org/pdf/2602.14487

The only thing you really need to know is how to generate a random value using your language of choice. 
Have fun, and happy (very late) π day!

Input Format
A single number; the amount of trials.

(Average your output between trials to get a more precise approximation.)

Output Format
An approximation of pi.
*/
int main(){
    srand(time(0));
    int n; cin >> n;
    double approxSum = 0.0;
    for(int i = 0; i < n; i++){
        int heads = 0; int tails = 0;
        while(heads <= tails){
            switch(rand() & 1){
                case 0:
                    tails++;
                    break;
                case 1:
                    heads++;
                    break;
            }
        }
        approxSum *= double(i)/double(i+1);
        approxSum += double(heads)/double(tails + heads)/double(i+1);
    }
    approxSum *= 4;
    cout << approxSum << endl;
    return 0;
}