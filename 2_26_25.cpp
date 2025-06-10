#include <iostream>
#include <string>
#include <sstream>
#include <bit>

using namespace std;

struct Integer{
    unsigned char arr[4] = {0, 0, 0, 0};

    Integer(int* num){copy((char*)(num), (char*)(num)+4, arr);}
    Integer(const Integer& other){copy(other.arr, other.arr+4, arr);};
    Integer(){}

    inline int getInt(){
        int returnInt;
        copy(arr, arr+4, (char*)(&returnInt));
        return returnInt;
    }
    inline char safeAccess(const int index) const{
        if(index>=0 && index<32){
            return ((char)(((arr[index>>3]) & (1<<(index&7)))!=0));
        }
        return 0;
    }
    
    inline Integer operator>>(const size_t rshift) const{
        Integer other = *this;
        other>>=rshift;
        return other;
    }
    inline void operator>>=(const size_t rshift){
        for(int i=0; i<32; i++){
            unsigned char mask = 1<<(i&7);
            arr[i>>3] &= ~mask;
            arr[i>>3] |= safeAccess(i+rshift)<<(i&7);
        }
    }
    inline Integer operator<<(const size_t lshift) const{
        Integer other = *this;
        other<<=lshift;
        return other;
    }
    inline void operator<<=(const size_t lshift){
        for(int i=31; i>=0; i--){
            unsigned char mask = 1<<(i&7);
            arr[i>>3] &= ~mask;
            arr[i>>3] |= safeAccess(i-lshift)<<(i&7);
        }
    }

    inline int leadingZeros() const{
        if(arr[3]!=0){return __countl_zero(arr[3]);}
        else if(arr[2]!=0){return __countl_zero(arr[2])+8;}
        else if(arr[1]!=0){return __countl_zero(arr[1])+16;}
        return __countl_zero(arr[0])+24;
    }
    inline Integer operator~() const{
        Integer other = Integer();
        for(int i=0; i<4; i++){
            other.arr[i] = ~arr[i];
        }
        return other;
    }

    Integer operator+(const Integer& other) const{
        Integer result = *this;
        result += other;
        return result;
    }
    void operator+=(const Integer& other){
        unsigned char carry = 0;
        unsigned char currentSelf, currentOther;
        unsigned char halfAdded;
        constexpr const unsigned char mask = (1<<7)-1;
        for(int i=0; i<4; i++){
            currentSelf = arr[i]; currentOther = other.arr[i];
            halfAdded = (currentSelf&mask) + (currentOther&mask);
            bool c1 = currentSelf>>7; bool c2 = currentOther>>7; bool c3 = halfAdded>>7;
            carry = (unsigned char)((c1 && c2) || (c2 && c3) || (c1 && c3));
            arr[i]=currentSelf+currentOther+carry;
        }
    }

    Integer operator-(const Integer& other) const{
        Integer result = *this;
        result-=other;
        return result;
    }
    void operator-=(const Integer& other){
        unsigned char carry = 1;
        unsigned char currentSelf, currentOther;
        unsigned char halfAdded;
        constexpr const unsigned char mask = (1<<7)-1;
        for(int i=0; i<4; i++){
            currentSelf = arr[i]; currentOther = ~other.arr[i];
            halfAdded = (currentSelf&mask) + (currentOther&mask) + carry;
            bool c1 = currentSelf>>7; bool c2 = currentOther>>7; bool c3 = halfAdded>>7;
            carry = (unsigned char)((c1 && c2) || (c2 && c3) || (c1 && c3));
            arr[i]=currentSelf+currentOther+carry;
        }
    }

    inline bool nonNeg(){
        return (arr[3]&(128))==0;
    }

    inline bool operator>=(const Integer& other) const{
        return (this->operator-(other)).nonNeg();
    }
    inline bool operator<=(const Integer& other) const{
        return other>=*this;
    }
    inline bool operator<(const Integer& other) const{
        return !this->operator>=(other);
    }
    inline bool operator>(const Integer& other) const{
        return other<*this;
    }
    inline bool operator==(const Integer& other) const{
        return this->operator>=(other) && this->operator<=(other);
    }
};

int main(){
    int num, div;
    cin >> num; 

    string temp;
    getline(cin, temp);
    stringstream ss;
    
    ss << temp.substr(1); ss >> div;
    Integer fakeDiv=Integer(&div), fakeNum=Integer(&num);

    Integer l = Integer(&div);
    l <<= min(fakeDiv.leadingZeros(), fakeDiv.leadingZeros()-fakeNum.leadingZeros()+1);
    if(fakeDiv.getInt() == 0 || l.getInt() == 0){cout << "Infinity" << endl; return 0;}

    Integer diff = fakeNum;
    while(l >= fakeDiv){
        diff -= l;
        if(diff.nonNeg()){fakeNum = diff;}
        else{diff = fakeNum;}
        l>>=1;
    }

    cout << fakeNum.getInt() << endl;
    return 0;
}