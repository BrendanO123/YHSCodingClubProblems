#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

/*
Optimal Cash Denominations

In your wallet, you have a number of cash bills of differing denominations. You want to pay a certain amount of money 
using the fewest number of bills possible. Given a list of cash denominations, the number of bills of each denomination,
and the amount of money to be paid, output the fewest number of bills needed to pay at least the amount — meaning, 
your final total may go over the amount. If it is impossible to pay the amount, output -1.

The first line of your input is the total amount to be paid. On each following line, the first number is the 
denomination of the bill, followed by a space, followed by the number of bills of that denomination you have. 
Do not assume that the denominations will be given in order.
*/
int main(){
    int total; string temp;
    cin >> total;

    vector<pair<int, int>> bills = vector<pair<int, int>>();

    int d, a;
    stringstream ss;
    getline(cin, temp);
    getline(cin, temp);
    while(!temp.empty() && !cin.eof()){
        ss << temp;
        ss >> d >> a;
        if(ss.bad()){break;}
        ss.clear();

        bills.emplace_back(d, a);
        getline(cin, temp);
    }

    sort(bills.begin(), bills.end());

    int count = 0;
    for(int i=bills.size()-1; i>=0; i--){
        total-=bills.at(i).first * bills.at(i).second;
        if(total<0){count+=ceil((total+bills.at(i).first * bills.at(i).second)/float(bills.at(i).first)); break;}
        else{count += bills.at(i).second;}
        if(total==0){break;}
    }
    if(total>0){cout << -1 << endl;}
    else{cout << count << endl;}
    return 0;
}

