#include <iostream>
#include <string>
#include <regex>

using namespace std;

/*
Fancy Frames

You need to create a program that generates ASCII art frames around text. 
Given some text (the "artwork"), a frame character, frame thickness, and padding size, 
your program should display the text surrounded by the specified frame.


Input Format

The input is a single line with four space-separated values: a b c d

a: The artwork text (1-15 alphanumeric characters)
b: The frame character (any single keyboard symbol)
c: The frame thickness (integer, 0 ≤ c ≤ 10)
d: The padding/gap between artwork and frame (integer, 0 ≤ d ≤ 20)

Note: If frame thickness is 0, padding is also 0

Output Format

Display the artwork centered with:
A gap of d spaces on all sides between the artwork and frame
A frame of thickness c made of character b surrounding everything
*/
int main(){
    string str;
    getline(cin, str);

    // complicated way to do Input().split(' ')
    auto delim = regex("\\s");
    auto tokenizer = sregex_token_iterator(str.begin(), str.end(), delim, -1);

    // get message and character
    string message = tokenizer->str(); tokenizer++;
    char c = tokenizer->str().at(0); tokenizer++;
    int messageWidth = message.size();

    // parse in thickness and padding
    int thickness = stoi(tokenizer->str()); tokenizer++;
    if(thickness == 0){cout << message << endl; return 0;}
    int padding = stoi(tokenizer->str());

    int lineWidth = messageWidth + 2 * (thickness + padding);
    char frameLineArr[lineWidth + 1];

    frameLineArr[lineWidth+1] = 0;
    memset(frameLineArr, c, lineWidth);
    string frameLine = string(frameLineArr);
    for(int i = 0; i < thickness; i++){cout << frameLine << endl;}

    char paddingLineArr[lineWidth + 1];
    paddingLineArr[lineWidth+1] = 0;
    memset(paddingLineArr, c, thickness);
    memset(paddingLineArr + thickness, ' ', messageWidth + 2 * padding);
    memset(paddingLineArr + lineWidth - thickness, c, thickness);

    string paddingLine = string(paddingLineArr);
    for(int i = 0; i < padding; i++){cout << paddingLine << endl;}

    for(int i = 0; i < thickness; i++){cout << c;}
    for(int i = 0; i < padding; i++){cout << ' ';}
    cout << message;
    for(int i = 0; i < padding; i++){cout << ' ';}
    for(int i = 0; i < thickness; i++){cout << c;}
    cout << endl;

    for(int i = 0; i < padding; i++){cout << paddingLine << endl;}
    for(int i = 0; i < thickness; i++){cout << frameLine << endl;}

    return 0;
}