#include <iostream>
#include <string>
#include <regex>

using namespace std;

/*
Validate IP Address

Given a string queryIP, return "IPv4" if IP is a valid IPv4 address, "IPv6" if IP is a valid IPv6 address or 
"Neither" if IP is not a correct IP of any type.

A valid IPv4 address is an IP in the form "x₁.x₂.x₃.x₄" where 0 <= xᵢ <= 255 and xᵢ cannot contain leading zeros. 
For example, "192.168.1.1" and "192.168.1.0" are valid IPv4 addresses while "192.168.01.1", "192.168.1.00", and 
"192.168@1.1" are invalid IPv4 addresses.

A valid IPv6 address is an IP in the form "x₁:x₂:x₃:x₄:x₅:x₆:x₇:x₈" where:
1 <= xᵢ.length <= 4
xᵢ is a hexadecimal string which may contain digits, lowercase English letter ('a' to 'f') and upper-case English 
letters ('A' to 'F'). Leading zeros are allowed in xᵢ.

For example, "2001:0db8:85a3:0000:0000:8a2e:0370:7334" and "2001:db8:85a3:0:0:8A2E:0370:7334" are valid IPv6 addresses, 
while "2001:0db8:85a3::8A2E:037j:7334" and "02001:0db8:85a3:0000:0000:8a2e:0370:7334" are invalid IPv6 addresses.

📃 Input Format

The input consists of a single string queryIP. queryIP consists only of English letters, 
digits and the characters '.' and ':'.

📝 Output Format

Print "IPv4" if queryIP is a valid IPv4 address, "IPv6" if queryIP is a valid IPv6 address or 
"Neither" if queryIP is not a correct IP of any type.
*/
int main(){
    string address;
    getline(cin, address);

    int len = address.length();
    sregex_token_iterator end;
    regex v6Pattern = regex("^([0-9a-fA-F]{1,4}:){7}[0-9a-fA-F]{1,4}$");
    regex v4Pattern = regex("^((0\\.)|([1-9][0-9]?[0-9]?\\.)){3}(0|([1-9][0-9]?[0-9]?))$");

    bool v6 = regex_match(address, v6Pattern);
    bool v4 = regex_match(address, v4Pattern);

    if(!(v4 || v6)){cout << "Neither" << endl; return 0;}

    regex v4Delim = regex("\\.");
    for(
        auto iter = sregex_token_iterator(address.begin(), address.end(), v4Delim, -1);
        iter != end;
        iter++ 
    ){
        int x = stoi(iter->str());
        if(x>=256){
            v4 = false;
            cout << "IPv6" << endl; return 0;
        }

    }
    if(!v4){cout << "IPv6" << endl; return 0;}
    if(!v6){cout << "IPv4" << endl; return 0;}
    return 0;
}