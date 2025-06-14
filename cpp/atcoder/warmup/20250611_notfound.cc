#include <iostream>
#include <string>
using namespace std;

void solve(){
    string s; cin >> s;

    bool arr[26] = {false};

    // make a boolean array where the characters in s are true
    for (int i = 0; i < s.size(); i++){
        arr[s[i] - 'a'] = true;
    }

    // if any are false still then print that out
    for (int i = 0; i < 26; i++){
        if (arr[i] == false){
            cout << static_cast<char>(i + 'a');
            return;
        }
    }
    return;

    // create an alphabet array
    // and index the alphabet flipping the bools
    // print the first bool thats not flipped

    //unordered set
    //run through the entire alphabet looking in the unordered set 

    //make a vector based on the string
    //remove the elements one by one

}

int main(){
    solve();
    return 0;
}
