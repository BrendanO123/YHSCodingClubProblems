#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

/*
Baseball Game

You are keeping the scores for a baseball game with unusual rules. At the beginning of the game, 
you start with an empty record.

You are given a space-separated list of operations, where each operation is one of the following:

- An integer `x`. -> Record a new score of x.
- '+'. -> Record a new score that is the sum of the previous two scores.
- 'D'. -> Record a new score that is the double of the previous score.
- 'C'. -> Invalidate the previous score, removing it from the record.

Output the sum of all the scores on the record after applying all the operations.

You may assume that, given the operation "+", there will always be at least two previous scores on the record.
You may also assume that, given the operations "C" or "D", there will always be at least one previous score on the record.
*/
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