#include <iostream>
#include <string>
#include <vector>

using namespace std;

// this solution is meant for version 2 of today's challenge, so it prints either circle or not circle 
// depending on if a point list forms a valid circle with one point being the center point
// it expects an input of:
/**
 * t
 * n
 * x y
 * ...
 * n
 * x y
 * ...
 * ...
 * 
 */
// where t is the test case count and n is the number of points 
// this is different from the first version of the problem where n is the number of points - 1 
// because the center point is explicitly given and is not counted


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
            if(j <= 2){points.emplace_back(x, y);} // add first three points to list

            if(j == 2){
                // once you have three points we can provenly find the center or there is not a circle
                // this is because if two points were valid centers, we would have an equilateral triangle with all three points
                // but it is impossible to have all three points fall on integer coordinates with an equilateral triangle
                // therefore this is exactly zero or one points that are equidistant from the other two points
                // this gives us the center point

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

            // once we have the center point, we just check if the new points lie along this circle
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