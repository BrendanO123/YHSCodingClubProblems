#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

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

