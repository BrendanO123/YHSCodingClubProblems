#include <iostream>

using namespace std;

int main(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int normal=-1;
    int alterante=-1;
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
        alterante = min(
            (a != x ? y : 0) + (b != y ? a : 0), //cut along entire height if width is not right, cut along width if height is not right
            (b != y ? x : 0) + (a != x ? b : 0) //cut along entire width if height is not right, cut across height if width is not right
        );
    }

    if(normal == -1){cout << alterante << endl; return 0;}
    cout << min(normal, alterante) << endl;

    return 0;
}