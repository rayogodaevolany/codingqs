#include <iostream>
#include <string>
using namespace std;

void solve(){
    string s;cin >> s;
    string res;
    for (int i = 0; i < static_cast<int>(s.size()); i++){
        if (static_cast<int>(s[i]) >= static_cast<int>('A')){
            res+=s[i];
        }
    }

    for (int j = 0; j < static_cast<int>(res.size()); j++){
        cout << res[j] << " ";
    }
}

int main(){
    solve();
    return 0;
}
