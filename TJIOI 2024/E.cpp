#include <iostream>

using namespace std;

/*
Cookie Monster has a x by y rectangular cookie cake. With his cookie cutter, he can cut the cake into
smaller pieces. Each cut should be made in a straight line that is parallel to the sides of the rectangle,
and should split the cake into 2 pieces.
The time it takes to make a cut is equal to the length of the cut. Find the minimum amount of time
Cookie Monster needs to spend cutting in order to cut off a rectangular piece with dimensions a by b.
The paper can be rotated, so a i by j rectangle is equivalent to a j by i rectangle.

Input
The first line will contain 4 integers x, y, a, and b (1 ≤ x, y, a, b ≤ 109).

Output
If it is impossible to cut off a a by b rectangle from the original x by y rectangle, print −1. Otherwise,
print the minimum amount of time Cookie Monster needs to spend cutting in order to do so.
*/
int main(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int normal=-1;
    int alternate=-1;
    if(a>x || b>y){normal=-1;}
    else{
        normal = min(
            (a != x ? y : 0) + (b != y ? a : 0), //cut along entire height if width is not right, cut along width if height is not right
            (b != y ? x : 0) + (a != x ? b : 0) //cut along entire width if height is not right, cut across height if width is not right
        );
    }

    //rotate
    int temp = y;
    y = x;
    x = temp;

    //try with other rotation
    if(a>x || b>y){cout << normal << endl; return 0;}
    else{
        alternate = min(
            (a != x ? y : 0) + (b != y ? a : 0), //cut along entire height if width is not right, cut along width if height is not right
            (b != y ? x : 0) + (a != x ? b : 0) //cut along entire width if height is not right, cut across height if width is not right
        );
    }

    if(normal == -1){cout << alternate << endl; return 0;}
    cout << min(normal, alternate) << endl;

    return 0;
}