#include <iostream>
#include <string>
using namespace std;

void solve(){
    string t, u; cin >> t >> u;

    // for every index t
    for (int i = 0; i < t.size(); i++){
        // flag
        bool ok = true;
        // for every of u
        for (int j = 0; j < u.size(); j++){
            // check that it works
            if (t[i+j] != u[j] && t[i+j] != '?'){
                ok = false;
            }
        }
        // if looped over every u and not false
        if (ok){
            cout << "Yes" << endl;
            return;
        }
    }
    cout << "No" << endl;
    return;

}

int main(){
    solve();
    return 0;
}
