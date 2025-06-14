#include <iostream>
using namespace std;

void solve(){
    int N; cin >> N;
    int arr[120];
    for (int i = 0; i< N; i++){
        cin >> arr[i];
    }

    // there are only 100 N
    // go through each one each time cout how many are greater 
    // then keep track of greatest
    

    int res = 0;
    // loop over how many x could be 
    for (int i = 0; i< (N + 1);i++){
        int count = 0;
        // loop over entire arr
        for (int j = 0; j < N; j++){
            if (i <= arr[j]){
                count++;
            }
        }
        // check if count is greater than i;
        if ( count >= i){
            res = max(i, res);
        }
    }
    cout << res << endl; 



}

int main(){
    solve();
    return 0;
}
