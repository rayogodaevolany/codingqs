#include <iostream>
#include <vector>
using namespace std;

void solve(){

    int q; cin >> q;
    int arr[220];
    for (int i = 0; i < 100; i++){
        arr[i] = 0;
    }

    int index = 99;
    for (int i = 100; i < q + 100; i++){
        int first; cin >> first;
        if ( first == 1) {
            cin >> arr[index + 1];
            index++;
        } else {
            cout << arr[index] << endl;
            index--;
        }
        
    }

}

int main(){
    solve();
    return 0;
}
