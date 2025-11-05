#include <iostream>
#include <string>

using namespace std;

/*
Mix 2 Decks

Create a program that takes two strings as input, each representing a stack of "cards". Return a single string 
that represents the two stacks "mixed" together.

The order should become: the first card in stack 1, the first card in stack 2, the second card in stack 1, 
then the second card in stack 2, until one of the decks runs out. If one deck is longer than the other, 
the remaining cards should be added to the end of the output string.

Your input will be two lines, representing each deck. Line 1 contains the number of cards, followed by a space, 
followed by the deck where each card is represented by a lowercase letter. The second line is the same as the 
first but for the second deck.
*/
int main(){
    int n1; string temp;
    int n2;

    cin >> n1;
    getline(cin, temp);

    char deck1[n1];
    for(int i=0; i<n1; i++){deck1[i]=temp.at(i+1);}


    cin >> n2;
    getline(cin, temp);

    char deck2[n2];
    for(int i=0; i<n2; i++){deck2[i]=temp.at(i+1);}


    int max = (n1 >= n2 ? n1 : n2);
    for(int i=0; i<max; i++){
        if(i<n1){cout << deck1[i];}
        if(i<n2){cout << deck2[i];}
    }
    cout << endl;

    return 0;
}