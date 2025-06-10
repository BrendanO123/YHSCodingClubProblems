#include <iostream>

using namespace std;

int main(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int normal=-1;
    int alterante=-1;
    if(a>x || b>y){normal=-1;}
    else{normal = min(y+(b!=y ? a : 0), x+(a != x ? b : 0));}

    int temp = y;
    y = x;
    x = temp;
    if(a>x || b>y){cout << normal << endl; return 0;}
    else{alterante = min(y+(b!=y ? a : 0), x+(a != x ? b : 0));}

    if(normal == -1){cout << alterante << endl; return 0;}
    cout << min(normal, alterante) << endl;

    return 0;
}