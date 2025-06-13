#include <iostream>
using namespace std;

void solve(){
    int N, L; cin >> N >> L;
    int arr[120];
    arr[0] = 0;
    for (int i = 1; i < (N - 1); i++){
        int x; cin >> x;
        arr[i] = (arr[i -1] + x) % L;
    }

    int count = 0;
    int tri = 0;
    int div = L/3;
    // At every point
    for (int i = 0; i< N; i++){
        // for every point
        for (int j = i; j <N; j++){
            // if div or divdiv + i is equal then count++
            if ((arr[i] + div) % L == arr[j] || (arr[i] + ( 2*div)) % L == arr[j]){
                tri++;
            }
            if (tri >= 2){
                count+= tri - 1;
            }
            tri = 0;
        }
    }
    cout << count << endl;

}

int main(){
    solve();
    return 0;
}
