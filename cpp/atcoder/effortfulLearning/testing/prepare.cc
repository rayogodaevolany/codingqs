#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> toys(n), boxes(n);
    for (int i = 0; i < n; i++){
        cin >> toys[i];
    }
    for (int i = 0; i < n; i++){
        cin >> boxes[i];
    }
    // should be ascending order
    sort(toys.begin(), toys.end());
    sort(boxes.begin(), boxes.end());

    bool once = false;
    int res = -1;
    for (int i = n; i > 0; i--){
        if (toys[i] < boxes[i - 1]){
            res = toys[i];
            once = true;
        } else if (toys[i] < boxes[i - 1] && once){
            cout << -1 << endl;
            return;
        }
    }
    if (!once) cout << toys[0] << endl;
    else cout << res << endl;
}

int main(){
    solve();
    return 0;
}
