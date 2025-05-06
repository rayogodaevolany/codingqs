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
    bool flag = false;

    // it needs to be total amount is N
    //implement brute force
    for (int i=0;i<=N;i++){
        for(int j=0;j<=N;j++){
            for(int m=0;m<=N;m++){
                if (i+j+m > N){
                    break;
                }
                if (i*10 + j*5 + m*1 == Y/1000 && !flag && ((i+j+m) == N)){
                    cout << i<< ' '<<  j<< ' ' << m;
                    flag = true;
                    break;
                }
            }
        }
    }

    if (!flag) {
        cout << -1 << ' '<< -1 << ' ' << -1;
    }

    return 0;
}
