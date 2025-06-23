#include <iostream>
#include <string>
using namespace std;

void solve(){
    string s; cin >> s;
    int l; cin >> l;

    if (s.size() >= l){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

int main(){
    solve();
    return 0;
}
