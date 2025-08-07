#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

void math(){
    int n; cin >> n;
    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        arr[i] = x;
    }
    
}
void solve(){
    int n; cin >> n;

    vector<vector<int>> dp(n, vector<int>(n, 0));

    vector<ll> arr(n);
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        arr[i] = (ll) x;
    }

    ll count = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (dp[i][j] == 1){
                count++;
            } else if (dp[i][j] == -1) {
                continue;
            } else if (dp[i][j] == 0){
                if ( (j - i) == (arr[j] + arr[i])){
                    count++;
                    dp[i][j] = 1;
                } else {
                    dp[i][j] = -1;
                }

            }

        }
    }
    cout << count << endl;
}

// void naive(){
//     int n; cin >> n;
//     vector<ll> arr(n);
//     for (int i = 0; i < n; i++){
//         ll x; cin >> x;
//         arr[i] = x;
//     }
    
//     ll count = 0;
//     for (ll i = 0; i < n; i++){
//         for (ll j = 0; j < n; j++){
//                 if ( (j > i) && (j - i) == ((ll) arr[j] + arr[i])){
//                     count++;
//                 }

//             }
//         }
//     cout << count << endl;
// }

int main(){
     solve();
    return 0;
}
