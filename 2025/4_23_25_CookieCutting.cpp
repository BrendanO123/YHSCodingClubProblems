#include <iostream>

using namespace std;

/*
See TJIOI 2024 problem E
*/
int main(){
    int x, y, a, b;
    cin >> x >> y >> a >> b;

    int normal=-1;
    int alternate=-1;
    if(a>x || b>y){normal=-1;}
    else{normal = min(y+(b!=y ? a : 0), x+(a != x ? b : 0));}

    int temp = y;
    y = x;
    x = temp;
    if(a>x || b>y){cout << normal << endl; return 0;}
    else{alternate = min(y+(b!=y ? a : 0), x+(a != x ? b : 0));}

    if(normal == -1){cout << alternate << endl; return 0;}
    cout << min(normal, alternate) << endl;

    return 0;
}