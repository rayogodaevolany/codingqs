#include <iostream>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++) cin >> arr[i];
    if (n%2 == 0){
        n = n - 1;
    } 

    int sum = 0;

    for (int j = 0; j < n; j += 2){
        sum+=arr[j];
    }

    cout << sum << endl;

}

int main(){
    solve();
    return 0;
}
