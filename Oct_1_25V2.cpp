#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

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