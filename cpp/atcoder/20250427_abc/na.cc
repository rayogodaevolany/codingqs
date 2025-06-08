#include <iostream>

using namespace std;


int main(){
    // if the given time is greater than the deadline yes or no
    
    int A, B, C, D; cin >> A >> B >> C >> D;

    bool flag = false;
    // if A is less than C then return no
    if (A < C){
        flag = false;
    }  else if ( A > C ){
    // else if A is greater than C return yes
        flag = true;
    } else {
    // else A is C
        if (B > D) {
        // if B is greater than D then return yes
            flag = true;
        } else {
        // else no
            flag = false;
        }
    }


    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
}
