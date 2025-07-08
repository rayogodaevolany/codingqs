#include <iostream>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[60];
    n--;
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    // for n times
    for (int i = 0; i < n; i++){
        // initiate res to distance 0
        int res = 0;
        for (int j = i; j < n; j++){
            // keep tally of res while looping
            res += arr[j];
            cout << res << " ";
        }
        cout << endl;
    }


}

int main(){
    solve();
    return 0;
}
