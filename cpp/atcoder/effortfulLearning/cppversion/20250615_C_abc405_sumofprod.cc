#include <iostream>
#include <vector>
using namespace std;

void solve(){
    int n; cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int x;cin >> x;
        vec.push_back(x);
    }
    int L = 0, R = 1, sum = 0;
    while(R < n){
        for (int j = R; j < n; j++){
            sum+=(vec[L]*vec[j]);
        }
        L++; R++;
    }
    cout << sum << endl;
}

int main(){
    solve();
    return 0;
}
