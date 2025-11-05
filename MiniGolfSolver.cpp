#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <vector>
#include "MiniGolfSolverMap.h"

using namespace std;

/*
The game, the ball can move up, down, left, or right, and the ball will continue in that direction until 
it runs into a wall or falls into the hole. After running into a wall, 
the ball will stop and be able to move in another direction again.

Your goal is that, given a "tiny golf" board, composed of walls (X), empty spaces (_), the ball's starting 
point (O , that is an O not a zero), and the hole/goal (4, it's a flag in case you were wondering), 
you must print the minimum amount of moves to get the ball into the hole, as well as
a specific sequence of moves (e.g. left right up) that gets the ball INTO the hole.

--------

Input:

The first line of the input is the amount of rows in the golf grid (height).
Following is the grid, with X for walls and _ for empty space. There will be an O where the ball starts and a 4 where the ball should finish

Example input:

8
XXXXXX
X____X
X_XX_X
X_XX_X
X_XX_X
X_XX_X
XOXX4X
XXXXXX
*/

/*
This is one of the first complex problems I tackled in this club and is the only, non-single-file solution, 
see also MiniGolfSolverMap.cpp and MiniGolfSolverMap.h
*/


//map that stores the # of steps to get to a square with the current best route and the move that was taken to get into that square
    //stored as a hash table bc most squares will not be landed on so a full array is overkill (also hash table is just as good)
unordered_map<pair<int,int>, pair<int, pair<int, char>>> movesFromStart = unordered_map<pair<int,int>,pair<int, pair<int, char>>>();

inline int getSingleAxisDist(pair<int, int> landingLoc, pair<int, int> origin){ //gets dist traveled when moving along an axis between two points 
    pair<int, int> temp =pair<int, int>(abs(landingLoc.first - origin.first), abs(landingLoc.second - origin.second));
    return (temp.first ? temp.first : temp.second);
}


//gives the possible moves that are worth exploring from a given point in the map
vector<pair<int, int>> getMoves(pair<int, int> position, Map map){

    vector<pair<int, int>> moves = vector<pair<int, int>>(); //list of moves
    int currentStep = movesFromStart.at(position).first; //current dist from origin


    for(int i = 0; i < 4; i++){ //for each move direction

        pair<int, int> hitLocation = map.getHit(position, directions[i]); //get move result location
        if(hitLocation!=position){ //if able to move in that direction
            if( //if this path is the best path to the square that has been found (least jumps from start to square or no path found yet)
                movesFromStart.find(hitLocation) == movesFromStart.end() || 
                movesFromStart.at(hitLocation).first > currentStep + 1
            ){

                //add to map (hashtable). Add num steps to get to square and details of last move for retracing steps 
                if(movesFromStart.find(hitLocation) == movesFromStart.end()){
                    movesFromStart.emplace(hitLocation, pair<int, pair<int, char>>(currentStep + 1, pair<int, char>(getSingleAxisDist(hitLocation, position), i)));
                }
                else{movesFromStart.at(hitLocation) = pair<int, pair<int, char>>(currentStep + 1, pair<int, char>(getSingleAxisDist(hitLocation, position), i));}

                moves.emplace_back(hitLocation); //add to new location to queue of squares to evaluate moves from
            }

            if(map.at(hitLocation) == FINISH){moves.clear(); return moves;} //if found finish, this branch is done   
                //bc stepping in any other direction will take longer than going straight to finish and if we r at finish we are done pathfinding
        }
    }
    return moves;
}

int main(){

    std :: cout << "Enter the Game Map Height and Character Array:" << std :: endl;

    Map map = Map(); //init game map (char array) and propagate from cin
    movesFromStart.emplace(map.getStartPos(), pair<int, pair<int, char>>(0, pair<int, char>(0,4))); //init hashtable


    //init exploration queue
    queue<pair<int, int>> pathCheckQueue = queue<pair<int, int>>();

    vector<pair<int, int>> moves = getMoves(map.getStartPos(), map); //get possible moves from start position
    for(pair<int, int> e : moves){pathCheckQueue.push(e);} moves.clear(); //propagate


    //loop through all move options until queue is empty
    while(!pathCheckQueue.empty()){
        pair<int, int> pos = pathCheckQueue.front(); pathCheckQueue.pop();
        moves = getMoves(pos, map); //get moves from next square and evaluate them, push new squares back into queue
        for(pair<int, int> e : moves){pathCheckQueue.push(e);} moves.clear();
    }
    if(movesFromStart.find(map.getFinishPos()) == movesFromStart.end()){ //if eval never reached end, exit
        std :: cout << "Puzzle is Not Possible." << std :: endl;
    }
    else{
        int steps = movesFromStart.at(map.getFinishPos()).first; //get num steps to reach finish
        std :: cout << "Puzzle Takes " << steps << " Moves to Complete." << std :: endl;

        //walk backwards from finish to start, store move list, and reverse order
        pair<int, int> iteratorPos = map.getFinishPos();
        char moves[steps];
        for(int i = steps-1; i >= 0; i--){
            if(movesFromStart.find(iteratorPos) == movesFromStart.end()){std :: cout << "ERROR FINISH POSITION NOT FOUND IN MOVE SEQUENCE" << std :: endl; break;}
            moves[i] = movesFromStart.at(iteratorPos).second.second;
            iteratorPos.first -= movesFromStart.at(iteratorPos).second.first * directions[int(moves[i])].first;
            iteratorPos.second -= movesFromStart.at(iteratorPos).second.first * directions[int(moves[i])].second;
        }

        //print move list from start to finish
        for(char e : moves){
            switch(e){
                case UP:
                    cout << "up ";
                    break;
                case DOWN:
                    cout << "down ";
                    break;
                case RIGHT:
                    cout << "right ";
                    break;
                case LEFT:
                    cout << "left ";
                    break;
                default:
                    cout << "NONE ";
                    break;
            }
        }
        std :: cout << std :: endl; //flush cout
    }

    return 0;
}