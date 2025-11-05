#include <iostream>

using namespace std;

/*
Cookie Monster and Elmo are playing yet another cookie-eating game. On his turn, Cookie Monster can
eat n cookies while Elmo can eat m cookies. If there are less cookies remaining than the number of cookies
the player is allowed to eat, they eat all of the cookies that are left.
The player who eats the last cookie is given the prestigious title of Cookie Connoisseur. If there are
initially c cookies and Cookie Monster starts eating cookies first, who is the Cookie Connoisseur?

Input
The first line contains 3 integers n, m, and c (1 ≤ n, m, c ≤ 109).

Output
Output a single string — Cookie Monster if Cookie Monster will win and Elmo if Elmo will win and be
named Cookie Connoisseur.
*/
int main(){

    //input
    int n, m, c;
    cin >> n >> m >> c;

    int R = c % (n+m);
    if(R == 0 || R > n){
        cout << "Elmo" << endl;
    }
    else{
        cout << "Cookie Monster" << endl;
    }

    return 0;
}
