#include <iostream>
using namespace std;


void solve(){
    int n, q; cin >> n >> q;
    int balls[120];
    for (int i = 0; i < q; i++) cin >> balls[i];

    int empty[120] = {0};
    int res[120];

    int index = 0;
    // for every ball
    for (int i = 0; i < q; i++){
        if (balls[i] >= 1){
            empty[balls[i] - 1] += 1;
            // place in order
            res[i] = balls[i];
        } else {
            //find minimun
            for (int j = n - 1; j >= 0; j--){
                if(empty[index] >= empty[j]){
                    index = j;
                }
            }
            empty[index] +=1;
            res[i] = index + 1;
            index = 0;
        }
    }
    for ( int i = 0; i < q; i++){
        cout << res[i] << " ";
    }
    cout << endl;
    // create empty array
    // create a results list
    // do the conditions looping over the arr

}

int main(){
    solve();
    return 0;
}
