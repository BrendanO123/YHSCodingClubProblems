#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>

using namespace std;

//enums for easier literals
enum BLOCKTYPES : char{
    START = 'O',
    FINISH = '4',
    WALL = 'X',
    AIR = '_'
};
enum DIRECTIONS : char{
    UP = 0,
    DOWN = 1,
    RIGHT = 2,
    LEFT = 3,
    NONE = 4
};
//list of possible directions to travel for storing path efficiently
constexpr const pair<int, int> directions[5] = {pair<int, int>(0, -1), pair<int, int>(0, 1), pair<int, int>(1, 0), pair<int, int>(-1, 0), pair<int, int>(0, 0)};

class Map{
    private:
        int width = 0;
        pair<int, int> startPos = pair<int, int>(-1, -1), finishPos = pair<int, int>(-1, -1); //start and end positions found when constructing map
        vector<vector<char>> map = vector<vector<char>>(); //game map stored as a char array
    public:
        Map(); //get map from cin

        pair<int, int> getStartPos(){return startPos;} pair<int, int> getFinishPos(){return finishPos;} //get key positions
        int getHeight(){return map.size();} int getWidth(){return width;} //get map size    deprecated? 
        bool isInBounds(pair<int, int> pos); //check lookup position against map bounds
        char at(pair<int, int> pos); //wrapper function for indexing 2D array with (x,y) pair
        pair<int, int> getHit(pair<int, int> origin, pair<int, int> step); //raycast move against game map
};