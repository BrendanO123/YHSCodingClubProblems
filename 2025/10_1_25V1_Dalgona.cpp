#include <iostream>
#include <string>
#include <vector>

using namespace std;

/*
Dalgona

ℹ️ UVA HSPC 2022, Problem A (https://acm.cs.virginia.edu/data/2022-contest.pdf)

You have chosen the circle shape for the infamous Dalgona game! However, upon opening your tin, 
you realize that somebody has already poked some holes into it. The cookie is represented on a two dimensional grid, 
defined by a center point.

There have also been some other points poked into the cookie, which are different from the center point. 
Making the slightly sub-optimal but still decent cookie choice, you wonder if the holes poked into the cookie 
will help you win this game or not. More specifically, you want to check if all the poked points fall on the perimeter 
of some circle. Solve this task quickly: you don’t have much time to win this game!

📃 Input Format
The first line of the input will be a single positive integer t ≤ 100. There will be t test cases that follow.
The first line of each test case consists of a single integer n ≤ 150. The next n lines consists of two 
single-space-separated integers −100 ≤ X[i], Y[i] ≤ 100 representing the coordinates of the i-th 
point poked into the cookie.

📝 Output Format
For each test case, print on a new line “Circle” if the points given are on the perimeter of some circle centered 
at the given central point, and “Not circle” otherwise.
*/
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