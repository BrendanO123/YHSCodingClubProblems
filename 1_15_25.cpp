#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

int main(){
    stack<int> scores = stack<int>();
    int sum = 0;

    string temp;
    getline(cin, temp);
    stringstream ss;

    for(int i=0; i <temp.size(); i++){

        char ctemp = temp.at(i);

        if(ctemp == ' ' || i==temp.size()-1){

            if(i==temp.size()-1 && ctemp != ' '){ss<<ctemp;}

            if(ss.str().at(0) == '+'){
                int previous = scores.top();
                scores.pop();
                int newScore = scores.top() + previous;
                scores.push(previous);
                scores.push(newScore);
                sum+=newScore;
            }
            else if(ss.str().at(0) == 'C'){
                sum-=scores.top();
                scores.pop();
            }
            else if(ss.str().at(0) == 'D'){
                sum+=2*scores.top();
                scores.push(2*scores.top());
            }
            else{
                int itemp;
                ss >> itemp;
                scores.push(itemp);
                sum+=itemp;
            }
            ss.clear();
            ss.str("");

        }
        else{ss << ctemp;}
    }

    cout << sum << endl;
    return 0;
}