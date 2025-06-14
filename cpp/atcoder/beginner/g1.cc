#include <iostream>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[120];
    for (int i = 0; i < n; i++) cin >> arr[i];
    int k; cin >> k;

    int count = 0;
    for ( int i = 0; i < n; i++) {
        if (arr[i] >= k){
            count++;
        }
    }
    cout << count << endl;


}

int main(){
    solve();
    return 0;
}
