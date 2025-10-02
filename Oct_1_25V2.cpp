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