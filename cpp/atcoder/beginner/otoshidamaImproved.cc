#include<iostream>
using namespace std;


// Is it possible.
// N bills and Y yen is it possible to have such a combination
// the brute force is that you do all possibilities of bills and see if it ever equals the amount of money
// but that would be 2000 cubed
// so you still kind of do a brute force

// The brute force works, now I need to make it work faster
int main() {
    int N, Y;
    cin >> N >> Y;

    int a = -1,b = -1,c = -1;
    
    // it needs to be total amount is N
    //implement brute force
    for (int i=0;i<=N;i++){
        for(int j=0;i+j<=N;j++){
            int m = N-(i+j);
                if (i*10000 + j*5000 + m*1000 == Y ){
                    a = i; b =j; c=m;
                }
        }
    }

    cout << a << ' ' << b << ' '<< c;

    return 0;
}
