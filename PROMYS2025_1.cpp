#include <iostream>
#include <string>
#include <sstream>

#include <filesystem>

#include <iostream>
#include <fstream>

using namespace std;

void makeTable(int size, int* arr){
    arr[0] = 0;
    bool targetFound = false;
    int min = 0;
    for(int i = 0; i< size; i++){
        arr[i] = i; arr[i * size] = i;
    }
    for(int y = 1; y < size; y++){
        for(int x=1; x<size; x++){
            min = x+y;
            for(int target = 0; target < x+y; target++){
                targetFound = false;
                for(int iterateX = 0; iterateX < x; iterateX ++){
                    if(arr[iterateX+y*size] == target){targetFound = true; break;}
                }
                if(targetFound){continue;}
                for(int iterateY = 0; iterateY < y; iterateY ++){
                    if(arr[x+iterateY*size] == target){targetFound = true; break;}
                }
                if(!targetFound){
                    min = target;
                    break;
                }
            }
            arr[x+y*size] = min;
        }
    }
}
bool printTable(int size, int* arr){
    /*for(int y = 0; y < size; y++){
        for(int x=0; x<size; x++){
            std :: cout << arr[x+y*size] << (x == size-1 ? "" : " | ");
        }
        std :: cout << std :: endl;
    }*/
    stringstream s;
    s << "numbers_" << (abs(size)) << ".csv";
    string name = s.str();
    ofstream file; file.open(name.c_str(), ios::out); 
    if(file.is_open()){

        for(int y = size-1; y >=0; y--){
            for(int x=0; x<size; x++){
                file << arr[x+y*size];
                if(x<size-1){file << ',';}
            }
            if(y>0){file << '\n';}
        }

        file << '\n' << '\n';
        file.close();
        return true;
    }
    else{file.close(); fprintf(stderr, "FAILED TO OPEN SAVE FILE");}
    return false;
}

int main(){
    cout << "Enter a size:" << endl;
    int n;
    cin >> n;
    if(cin.bad()){
        std :: cout << "NAN; Please Enter an Integer" << endl;
        return -1;
    }
    int* nums = new int[n*n];
    makeTable(n, nums);
    printTable(n, nums);
    delete[] nums;
    return 0;
}