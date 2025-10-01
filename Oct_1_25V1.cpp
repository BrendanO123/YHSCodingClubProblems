#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(){
    int t; string temp;
    cin >> t;
    getline(cin, temp);

    for(int i=0; i<t; i++){
        int n, x, y;
        cin >> n;
        getline(cin, temp);

        pair<int, int> center = pair<int, int>(0, 0);
        int distance_squared = 0;
        vector<pair<int, int>> points = vector<pair<int, int>>();
        for(int j = 0; j < n; j++){
            cin >> x >> y; getline(cin, temp);
            auto e = pair<int, int>(x, y);
            if(j <= 2){points.emplace_back(x, y);}

            if(j == 2){
                int dx = (points.at(2).first - points.at(0).first);
                int dy = (points.at(2).second - points.at(0).second);
                int d20 = dx * dx + dy * dy;

                dx = (points.at(1).first - points.at(0).first);
                dy = (points.at(1).second - points.at(0).second);
                int d10 = dx * dx + dy * dy;
                if(d10 == d20){center = points.at(0); distance_squared = d10;}
                else{
                    dx = (points.at(2).first - points.at(1).first);
                    dy = (points.at(2).second - points.at(1).second);
                    int d21 = dx * dx + dy * dy;

                    if(d21 == d10){center = points.at(1); distance_squared = d10;}
                    else{
                        if(d21 == d20){center = points.at(2); distance_squared = d20;}
                        else{cout << "Not Circle" << endl; return 0;}
                    }
                }
            }

            if(j > 2){
                int dx = e.first - center.first;
                int dy = e.second - center.second;

                if(dx * dx + dy * dy != distance_squared){cout << "Not Circle" << endl; return 0;}
            }
        }
        cout << "Circle" << endl;
    }
    return 0;
}