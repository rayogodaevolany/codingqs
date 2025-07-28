#include <iostream>
#include <unordered_set>
#include <string>
#include <vector>
using namespace std;
void solve(){
    int n; cin >> n;
    vector<string> vec(n);
    for (int i = 0; i < n; i++){
        cin >> vec[i];
    }
    unordered_set<string> strs;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (i != j){
                string tmp = vec[i] + vec[j];
                strs.insert(tmp);
            }
        }
    }
    cout << strs.size() << endl;
}

int main(){
    solve();
    return 0;
}
