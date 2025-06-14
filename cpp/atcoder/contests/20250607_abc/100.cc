#include <iostream>
#include <string>
using namespace std;

void solve(){
    int N; cin >> N;
    string T,A; cin >> T >> A;
    for (int i=0; i < N; i++){
        if ( T[i] == 'o' && T[i] == A[i]){
            cout << "Yes" << endl;
            return;
        }
    }

    cout << "No" << endl;
    return;

}

int main(){
    solve();
    return 0;
}

