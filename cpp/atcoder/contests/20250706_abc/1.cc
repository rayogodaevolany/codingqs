#include <iostream>
using namespace std;

void solve() {
    int n,m; cin >> n >> m;
    int sum = 0;
    for (int i = 0; i < n; i++){
        int x; cin >> x;
        sum += x;
    }
    if (sum <= m){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
int main() {
    solve();
    return 0;
}
