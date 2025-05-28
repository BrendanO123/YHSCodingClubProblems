#include <iostream>
#include <string>
#include <numeric>

using namespace std;

int n, m;
int inline getIndex(int y, int x){return x+y*(n+1);}

int main(){
    //TODO: test if O(n^2) is fast enough

    //settings
    int maxValue = 100;

    //input
    cin >> n >> m;

    string temp;
    getline(cin, temp);

    int* a = new int[n]; int sum=0; //int a[n];
    for(int i=0; i<n; i++){cin >> a[i]; sum+=a[i];}

    //prelimary calculations
    //Note I need to account for some of the cells over flowing back to zero but not all
    //also turning high values into negatives and whatnot
    if(sum%(m+1)!=0){cout << "NO" << endl; return 0;}

    int df = std :: gcd(n,m+1)-1;
    int cols = n-df;
    int gap = n-m-1;

    //memory allcation
    float* mat = new float[(n+1)*(n+1)];

    //basic initializtion loops
    for(int y=0; y<n; y++){
        for(int x=0; x<n; x++){mat[getIndex(y,x)]=0;}

        if(y<cols){mat[getIndex(y,y)]=1;}
        int minus = (y+gap)%(n); if(minus<cols){mat[getIndex(y,minus)]=-1;}

        mat[getIndex(y,n)]=a[y]-a[(y-1+n)%n];
    }
    for(int x=0; x<n-m-1;x++){mat[getIndex(n,x)]=0;}
    for(int x=n-m-1; x<cols;x++){mat[getIndex(n,x)]=1;}

    mat[getIndex(n,n)]=a[n-1];
    delete [] a;

    //finished initialization:
    /*** we now have a matrix of every linear equation with the free variables zeroed and ignored
     * we also have the difference of the two adjacent equations baked in instead of the full span row vectors to save time
     * to compensate for the lost information, the lowest row vector from the original equations is appended
     * 
     * Initial conditions:
        * matrix: 
        * {
        * {1, '0'*(n-m-2), -1, '0'*(m), a[0]-a[n-1]},
        * {0, 1, '0'*(n-m-2), -1, '0'*(m-1), a[1]-a0},
        * {0, 0, 1, '0'*(n-m-2), -1, '0'*(m-2), a[2]-a[1]},
        * ...
        * {'0'*(n-m-2), -1, '0'*m, 1, a[n-1]-a[n-2]},
        * {'0'*(n-m-1), '1'*(m+1), a[n-1]}
        * }
     */

    //reduced row echelon calculations
    int XPos=0;
    for(int y=0; y<n+1; y++){
        if(mat[getIndex(y,XPos)]){
            if(mat[getIndex(y,XPos)]!=1){
                float div = 1.0f/mat[getIndex(y,XPos)];
                for(int x=XPos; x<n+1; x++){if(mat[getIndex(y,x)]){mat[getIndex(y,x)]*=div;}}
            }
            for(int colHeight=0; colHeight<n+1; colHeight++){
                if(colHeight!=y && mat[getIndex(colHeight,XPos)]!=0){
                    float mult = -mat[getIndex(colHeight,XPos)];
                    for(int x=0; x<n+1; x++){
                        if(mat[getIndex(y,x)]){
                            mat[getIndex(colHeight,x)]+=mult*mat[getIndex(y,x)];

                        }
                    }
                }
            }
            XPos++;
        }
    }

    cout << "YES" << endl;
    int x=0;
    for(int y=0; y<n+1; y++){
        if(mat[getIndex(y,x)]){
            int value = int(mat[getIndex(y,n)]);
            while(value<0){value+=maxValue;}
            while(value>=maxValue){value-=maxValue;}
            cout << value << ' ';
            x++;
        }
    }
    for(int i=0; i<df; i++){cout << "0 ";}
    cout << endl;

    delete [] mat;

    //Aux Space: O(n^2) for a (n+1)x(n+1) matrix
    //Time: O(n^2) bc O(n^3) row reduced matrix generation is speed up thanks to O(n) reduction of all but one row vector to span of 3
    return 0;
}