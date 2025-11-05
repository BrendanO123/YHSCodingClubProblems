#include <iostream>
#include <string>
#include <limits>

using namespace std;

/*
Since Cookie Monster is quite clumsy and lacks dexterity, he struggles to execute the common cookie
shuffling techniques. Instead, he has invented a rudimentary shuffling algorithm called the k-Stack Shuffle.

A deck is a stack of n cookies, where each of these cookies contains a unique number of chocolate chips
in the range [1, n]. In other words, the number of chocolate chips in a deck of n cookies is a permutation
of the integers from 1 to n. We will refer to the cookie with i chocolate chips as cookie i.

A k-Stack Shuffle with a deck of n cookies is as follows:
1. Initialize k empty stacks numbered from 1 to k.
2. Remove the cookie at the top of the deck and place it at the top of one of the k stacks. Repeat this
step n times.
3. Take all the cookies in stack 1 and put them top of stack 2. Then, take the combined stack 1 and
2 and put it on top of stack 3. Repeat this process until you have one stack left. This stack is the
new, shuffled deck.

Unfortunately, there have been several complaints involving Cookie Monster’s new shuffling technique. In
particular, the resulting shuffled deck is often very convenient for Cookie Monster, leading to accusations
that he is not shuffling the deck randomly.

There are t particularly suspicious instances that suggest Cookie Monster may have been cheating. For
each instance, the original stack was in sorted order (the cookies were labeled 1 to n from top to bottom)
and the shuffled deck is given to you. Your task is to find the minimum possible k that could have been
used in the k-Stack Shuffle. In other words, find the minimum k such that Cookie Monster could have
used the k-Stack Shuffle technique to shuffle the sorted deck and obtain the given shuffled deck.

Input
The first line of the input will contain the integer t (1 ≤ t ≤ 105), the number of suspicious instances.
The first line of each test case will contain the integer n (1 ≤ n ≤ 2 · 105), the size of the deck of cookies.
The second line of each test case will contain n integers a1 . . . an (1 ≤ ai ≤ n, ai 6= aj whenever i 6= j),
the order of the cookies in the shuffled deck from top to bottom.
It is guaranteed that the sum of n over all test cases does not exceed 2 · 105.

Output
Print t lines, the minimum k that Cookie Monster could have used in each instance.
*/
int main(){

    //input
    int t;
    string temp;
    cin >> t;
    getline(cin, temp);

    int out[t];
    for(int i = 0; i < t; i++){
        int n;
        cin >> n;
        getline(cin, temp);

        int k = 1;
        int last = INT_LEAST32_MAX;
        int a;
        for(int j = 0; j < n; j++){
            cin >> a;
            if(a>=last){k++;}
            last=a;
        }
        getline(cin, temp);

        out[i] = k;
    }

    for(int i = 0; i < t; i++){
        cout << out[i] << endl;
    }


    return 0;
}