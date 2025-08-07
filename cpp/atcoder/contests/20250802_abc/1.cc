#include <iostream>
using namespace std;

void solve(){
    int n; cin >> n;
    int arr[110];
    for (int i = 0; i < n; i++){
        cin >> arr[i];
        if (arr[i - 1] && arr[i - 2]){
            if (arr[i] == arr[i - 1] && arr[ i-1] == arr[i -2]){
                cout << "Yes" << endl;
                return;
            }
        }
    }
    cout << "No" <<endl;
    return;
}

int main(){
    solve();
    return 0;
}
