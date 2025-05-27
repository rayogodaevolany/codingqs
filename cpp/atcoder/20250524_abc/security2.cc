#include <iostream>
#include <string>
using namespace std;

// how many button presses to get string S?
// bruteforce first

// remove num from each succesively and then count the steps
// all possible button presses?
void solve(){
    // S is the target string
    string S; cin >> S;

    int count = 0;
    // repeat string length
    for (int i = 0; i <= S.size(); i++){

        // get last digit add to count 
        count += static_cast<int>(S.back());
        // remove last value
        S.pop_back();

        // and process the string 
        // go through the string
        for (int j = 0; j < (S.size()); j++){
            // if not nine then add one
            if (S[j] != 9){
                S[j] += 1;
            // if nine make 0
            } else {
                S[j] = 0;
            }
        }
        // add to count one
        count++;
    }

    cout << count << endl;
}

int main(){
    solve();
    return 0;
}
