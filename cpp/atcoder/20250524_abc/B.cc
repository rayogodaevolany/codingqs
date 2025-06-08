#include <iostream>
#include <iomanip>
using namespace std;

// the probability that at least one
// sum is at least X
// abs diff is at least Y
//
// probab of n1 + n2 is x
// and abs(n1 - n2) is at least y
//
// all possibilities 
// then count of one die div by 6 
// and count of other by 6
void solve(){
    int X, Y; cin >> X >> Y;
    int count = 0;
    // loop over 6 
    for (int i = 1; i <= 6; i++){
    //      loop over 6
        for (int j = 1; j <= 6; j++){
            if( (i + j) >= X){
                count++;
            } else if ( abs(i - j) >= Y){
                count++;
            }
         }
     }
    cout << setprecision(10) << static_cast<double>(count)/ static_cast<double>(36) << endl;

    // divide the count of possibilities by 36
}
int main(){
    solve();
    return 0;
}
