#include <iostream>
#include <unordered_map>
#include <string>
#include <vector>
using namespace std;

// sliding window
void solve(){
    unordered_map<int, int> hash;
    string s; cin >> s;
    vector <bool> indices(s.size());

    for (int i = 0; i < (int)s.size(); i++){
        if (s[i] == 'W'){
            indices[i] = true;
        } else if (s[i] == 'A'){
            int pointer = i - 1;
            // while not out of bounds and is W
            while (pointer >= 0 && indices[pointer]){
                s[pointer+1] = 'C';
                pointer--;
            }
            s[pointer+1] = 'A';
        }
    }
    cout << s.c_str()<<endl;
}

int main(){
    solve();
    return 0;
}
