#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

// this solution is meant for version 3 of today's challenge
// like the previous solution, it expects the number of points in each test case to count the center point of the circle
// there may be points that do not fall on the circle
// it outputs the maximum count of points that fall on a circle with one of the points as its center
// assuming the circle is drawn optimally with the optimal radius and center point 

/*
Dalgona

ℹ️ UVA HSPC 2022, Problem A (https://acm.cs.virginia.edu/data/2022-contest.pdf)

You have chosen the circle shape for the infamous Dalgona game! However, upon opening your tin, 
you realize that somebody has already poked some holes into it. The cookie is represented on a two dimensional grid.

There have also been some other points poked into the cookie, which are different from the center point. 
Making the slightly sub-optimal but still decent cookie choice, you wonder if the holes poked into the cookie 
will help you win this game or not. More specifically, you want to find how many of the poked points fall on the perimeter 
of some circle. 

Output the MAXIMUM AMOUNT OF POINTS that could lie on some circle, assuming the circle you chose 
maximizes that amount. Don't just say whether the points lie on a circle or not. Output the most points that could 
make up a circle. Solve this task quickly: you don’t have much time to win this game!

📃 Input Format
The first line of the input will be a single positive integer t ≤ 100. There will be t test cases that follow.
The first line of each test case consists of a single integer n ≤ 150. The next n lines consists of two 
single-space-separated integers −100 ≤ X[i], Y[i] ≤ 100 representing the coordinates of the i-th 
point poked into the cookie.

📝 Output Format
Output the MAXIMUM AMOUNT OF POINTS that could lie on some circle, assuming the circle you chose 
maximizes that amount.
*/
int getPointCount(vector<pair<int, int>> points, int index){

    unordered_map<int, int> radiusPointCount = unordered_map<int, int>();
    auto center = points.at(index);
    int maxCount = 0;
    for(int i = 0; i < points.size(); i++){
        if(i == index){continue;}
        int dx = points.at(i).first - center.first;
        int dy = points.at(i).second - center.second;

        int d2 = dx * dx + dy * dy;
        if(radiusPointCount.find(d2) == radiusPointCount.end()){
            radiusPointCount.emplace(d2, 1);
        }
        else{radiusPointCount.at(d2)++;}
        if(radiusPointCount.at(d2) > maxCount){maxCount = radiusPointCount.at(d2);}
    }
    return maxCount;
}

// this one is far more boring than the other one which is why I included the "easier" one as well
// the other one had a clever trick to be O(N) by finding the center point in constant time 
// then simply iterating through each point after finding the center and ensuring constant distance

// this one, on the other hand, doesn't assume all points are on the circle so we cannot find the center point easily
// therefore, we instead simply loop through each point as the center point and find the max number of points that can fall on a circle with that center
// this is done by simply finding the distance from our center point to each other point and adding the distances to a hashmap

// once that is done, we simply fnd the max count from all of the center points and return it

int main(){
    int t; string temp;
    cin >> t;
    getline(cin, temp);

    for(int set=0; set<t; set++){
        int n, x, y;
        cin >> n;
        getline(cin, temp);

        vector<pair<int, int>> points = vector<pair<int, int>>();
        for(int j = 0; j < n; j++){
            cin >> x >> y; getline(cin, temp);
            points.emplace_back(x, y);
        }

        int maxPoints = 0;
        for(int i=0; i < n; i++){
            int pointCount = getPointCount(points, i);
            if(pointCount > maxPoints){maxPoints = pointCount;}
        }

        cout << maxPoints << endl;
    }
    return 0;
}