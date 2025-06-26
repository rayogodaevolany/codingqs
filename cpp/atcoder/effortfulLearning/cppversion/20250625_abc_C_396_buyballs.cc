#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// USE MAKE HEAP
// or just sort it
// and keep a prefix sum

// use a greedy approach to only check for the max in each set
// then check the whole sets, this would make it o(n) rather than quadratic
void solve(){
    int n, m; cin >> n >>m;
    vector<int> prefixblack(n);
    vector<int> prefixwhite(m);
    for (int i = 0; i < n; i++){
        cin>>prefixblack[i];
    }
    sort(prefixblack.begin(), prefixblack.end(), greater<>());

    for (int i = 0; i < n; i++){
        if (i > 0){
            if (prefixblack[i] + prefixblack[i-1] > prefixblack[i]){
                prefixblack[i] += prefixblack[i - 1];
            }
        }
    }

    for (int i = 0; i < m; i++){
        cin>>prefixwhite[i];
    }

    sort(prefixwhite.begin(), prefixwhite.end(), greater<>());

    for (int i = 0; i < m; i++){
        if (i > 0){
            if (prefixwhite[i] + prefixwhite[i-1] > prefixwhite[i]){
                prefixwhite[i] += prefixwhite[i - 1];
            }
        }
    }


    int maxsum = 0;
    for (int i = 0; i < n; i++){
        int count = prefixwhite[i] + prefixblack[i];
        maxsum = max(maxsum, count);
    }
    cout << maxsum << endl;
}

int main(){
    solve();
    return 0;
}
