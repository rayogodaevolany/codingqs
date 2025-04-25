#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

// given a string is it possible to make it with some
// hardcoded values?
int main(){
    string test[4] = {"dream", "dreamer", "erase", "eraser"};
    
    string S;
    getline(cin, S);
    //reverse string S 
    reverse(S.begin(), S.end());
    for (int i=0;i<4;i++){
        // reverse all of the other strings
        reverse(test[i].begin(), test[i].end());
    }

    // cut from the ends?
    bool canDiv = true;
    // loop until the end of S
    for (int i=0;i<S.size();){
        // divByText is the bool for whether S can be divided by any of the 4
        bool divByText = false;

        // loop for the 4 strings
        for(int j=0;j<4;j++){
            string divisor = test[j];
            // get substring of S from index to index + dividing string size
            if (S.substr(i, divisor.size())==divisor){
                divByText = true;
                // increment i by the size of the dividing text
                i += divisor.size();
            }
        }
        if(!divByText){
            canDiv=false;
            break;
        }
    }
    if(canDiv) cout << "YES" << '\n';
    else cout << "NO" << '\n';

    return 0;
}
