#include "MiniGolfSolverMap.h"

Map :: Map(){
    ///get height   no longer used for anything except throwing errors, code is leftover from when I thought the # was the width of the map
    int height;
    cin >> height;
    if(cin.bad()){
        std :: cout << "BAD MAP SIZE VALUE" << std :: endl; return; // make sure they actually put in a number
    }

    //set up vars for loading in input
    string temp; int i = 0;
    getline(cin, temp); getline(cin, temp);

    //loop through text input to make map and find start/end positions
    while(temp.size() && i < height){

        map.emplace_back(vector<char>()); //add row
        if(width == 0){width = temp.size();} //set width value
        map.at(map.size()-1).reserve(width); //reserve row width

        //iterate through row
        for(int i = 0; i < width; i++){
            map.at(map.size()-1).emplace_back(i) = temp.at(i); //set char

            //check for key position while avoiding dupes
            if(temp.at(i) == START){
                if(startPos != pair<int, int>(-1, -1)){std :: cout << "CANNOT PROCESS MULTIPLE START POSITIONS" << std :: endl; return;}
                startPos = pair<int, int>(i, map.size()-1); //0,0 is top left 
            }
            if(temp.at(i) == FINISH){
                if(finishPos != pair<int, int>(-1, -1)){std :: cout << "CANNOT PROCESS MULTIPLE FINISH POSITIONS" << std :: endl; return;}
                finishPos = pair<int, int>(i, map.size()-1); //0,0 is top left 
            }

        }
        i++; if(i<height){getline(cin, temp);} //get next row
    }
    if(map.size() != height){std :: cout << "INCORRECT MAP HEIGHT" << std :: endl; return;} //complain for literally no reason
}

bool Map :: isInBounds(pair<int, int> pos){ //check position against bounds
    if(pos.second >=0 && pos.second<map.size()){if(pos.first>=0 && pos.first < map.at(0).size()){return true;}}
    return false;
}
char Map :: at(pair<int, int> pos){return map.at(pos.second).at(pos.first);} //lookup function using (x,y) pair 
pair<int, int> Map :: getHit(pair<int, int> origin, pair<int, int> step){ //raycast function to iterate through map until something is hit
    pair<int, int> pos = pair<int, int>(origin.first + step.first, origin.second + step.second);
    while(isInBounds(pos)){
        if(at(pos) != AIR && at(pos) != START){break;} //if hit something, done
        pos.first += step.first; pos.second += step.second;
    }
    if(at(pos) != FINISH){pos.first-=step.first; pos.second-=step.second;}
    return pos;
}