#include <iostream>

using namespace std;

/*
Cookie Monster currently has x chocolate chip cookies, y snickerdoodle cookies, and z macadamia cookies.
He wants to eat as many good snacks as possible, where a good snack consists of exactly two cookies with
different types.
However, Elmo stole and ate all of his macadamia cookies! Determine how many good snacks Cookie
Monster can eat after having his macadamia cookies stolen.

Input
The first line will contain 3 integers x, y, and z (1 ≤ x, y, z ≤ 109).

Output
Output a single integer — the maximum number of good snacks Cookie Monster can eat.
*/
int main(){

    //input
    int x, y, z;
    cin >> x >> y >> z;
    cout << min(x, y) << endl;

    return 0;
}
