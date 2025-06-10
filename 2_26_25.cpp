#include <iostream>
#include <string>
#include <sstream>
#include <bit>

using namespace std;

template <size_t length>
struct BigInt{
    private:
        size_t len;
    public:
        unsigned char arr[length];

        BigInt(char* num) : len(length){copy((num), (num)+length, arr);}
        BigInt(const BigInt& other) : len(length){
            copy(other.arr, other.arr + min(len, other.len), arr); 
            memset((void*)(arr + min(len, other.len)), 0, len);
        }
        BigInt() : len(length){}

        inline long long getLong(size_t offset = 0) const{
            long long returnInt = 0L;
            if(offset<0){offset=0;}
            copy(arr + min(length, offset), arr + min(length, offset+sizeof(long long)), (char*)(&returnInt));
            return returnInt;
        }
        inline char safeAccess(const size_t index) const{
            if(index>=0 && index<length*8){
                return ((char)(((arr[index>>3]) & (1<<(index&7)))!=0));
            }
            return 0;
        }
        
        inline unsigned char operator[](const size_t i) const{
            if(i>=0 && i<length){return arr[i];}
            return 0;
        }

        inline BigInt<length> operator>>(const size_t rshift) const{
            BigInt other = *this;
            other>>=rshift;
            return other;
        }
        inline void operator>>=(const size_t rshift){
            for(int i=0; i<length*8; i++){
                arr[i>>3] &= ~(1<<(i&7));
                arr[i>>3] |= safeAccess(i+rshift)<<(i&7);
            }
        }
        inline BigInt<length> operator<<(const size_t lshift) const{
            BigInt other = *this;
            other<<=lshift;
            return other;
        }
        inline void operator<<=(const size_t lshift){
            for(int i=length*8-1; i>=0; i--){
                arr[i>>3] &= ~(1<<(i&7));
                arr[i>>3] |= safeAccess(i-lshift)<<(i&7);
            }
        }

        inline int leadingZeros() const{
            size_t offset = 0;
            for(int i=length-1; i>0; i--){
                if(arr[i]!=0){return __countl_zero(arr[i]+offset);}
                offset+=8;
            }
            return __countl_zero(arr[0])+offset;
        }
        inline BigInt<length> operator~() const{
            BigInt<length> other = BigInt<length>();
            for(int i=0; i<length; i++){
                other.arr[i] = ~arr[i];
            }
            return other;
        }

        inline BigInt<length> operator+(const BigInt& other) const{
            BigInt<length> result = BigInt<length>(*this);
            result += other;
            return result;
        }
        void operator+=(const BigInt& other){
            unsigned char carry = 0;
            unsigned char currentSelf, currentOther;
            unsigned char halfAdded;
            constexpr const unsigned char mask = (1<<7)-1;
            for(int i=0; i<length; i++){
                currentSelf = arr[i]; currentOther = (i < other.len ? other.arr[i] : 0);
                halfAdded = (currentSelf&mask) + (currentOther&mask);
                bool c1 = currentSelf>>7; bool c2 = currentOther>>7; bool c3 = halfAdded>>7;
                carry = (unsigned char)((c1 && c2) || (c2 && c3) || (c1 && c3));
                arr[i]=currentSelf+currentOther+carry;
            }
        }

        inline BigInt<length> operator-(const BigInt& other) const{
            BigInt<length> result = BigInt<length>(*this);
            result -= other;
            return result;
        }
        void operator-=(const BigInt& other){
            unsigned char carry = 1;
            unsigned char currentSelf, currentOther;
            unsigned char halfAdded;
            constexpr const unsigned char mask = (1<<7)-1;
            for(int i=0; i<length; i++){
                currentSelf = arr[i]; currentOther = ~(i < other.len ? other.arr[i] : 0);
                halfAdded = (currentSelf&mask) + (currentOther&mask) + carry;
                bool c1 = currentSelf>>7; bool c2 = currentOther>>7; bool c3 = halfAdded>>7;
                carry = (unsigned char)((c1 && c2) || (c2 && c3) || (c1 && c3));
                arr[i]=currentSelf+currentOther+carry;
            }
        }

        inline bool nonNeg(){
            return (arr[length-1]&(128))==0;
        }

        inline bool operator>=(const BigInt& other) const{
            return (this->operator-(other)).nonNeg();
        }
        inline bool operator<=(const BigInt& other) const{
            return other>=*this;
        }
        inline bool operator<(const BigInt& other) const{
            return !this->operator>=(other);
        }
        inline bool operator>(const BigInt& other) const{
            return other<*this;
        }
        inline bool operator==(const BigInt& other) const{
            return this->operator>=(other) && this->operator<=(other);
        }
        inline bool operator==(const int& other) const{
            BigInt<length> comp = BigInt<length>((char*)&other);
            return this->operator>=(comp) && this->operator<=(comp);
        }

        BigInt operator%(const BigInt div) const{
            BigInt<length> num = BigInt<length>(*this);
            BigInt<length> diff = BigInt<length>(*this);
            BigInt<length> l = BigInt<length>(div);

            l <<= min(div.leadingZeros(), div.leadingZeros()-leadingZeros()+1);
            if(div == 0 || l == 0){return num;}

            while(l>=div){
                diff -= l;
                if(diff.nonNeg()){num = diff;}
                else{diff = num;}

                l>>=1;
            }

            return num;
        }

        BigInt operator/(const BigInt div) const{
            BigInt<length> num = BigInt<length>(*this);
            BigInt<length> diff = BigInt<length>(*this);
            BigInt<length> q = BigInt<length>();
            BigInt<length> l = BigInt<length>(div);

            size_t i = min(div.leadingZeros(), div.leadingZeros()-leadingZeros()+1);
            l <<= i;
            if(div == 0 || l == 0){return num;}

            while(l>=div){
                diff -= l;
                if(diff.nonNeg()){num = diff; q[i>>3] |= 1<<(i&7);}
                else{diff = num;}

                l>>=1;
                i--;
            }

            return q;
        }

        BigInt operator*(const BigInt b) const{
            BigInt<length> num = BigInt<length>();

            for(size_t i=0; i<length; i++){
                if(safeAccess(i)){num+=(b<<i);}
            }
            return num;
        }
};

int main(){
    int num, div;
    cin >> num; 

    string temp;
    getline(cin, temp);
    stringstream ss;
    
    ss << temp.substr(1); ss >> div;
    BigInt<4> intDiv=BigInt<4>((char*)&div), intNum=BigInt<4>((char*)&num);

    cout << (intNum%intDiv).getLong() << endl;
    return 0;
}