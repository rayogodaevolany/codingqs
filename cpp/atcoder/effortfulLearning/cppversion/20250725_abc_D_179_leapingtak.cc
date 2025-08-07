#include <iostream>
using namespace std;

vector<int> findset(int n, int k, vector<pair<int, int>> data){
    vector<int> dist (n);
    for (int i = 0; i < k; i++){
        dist[data[i].first]++;
        dist[data[i].second]--;
    }
    vector<int> unionarr(n);
    unionarr[0] = dist[0];
    for (int i = 1; i < n; i++){
        unionarr[i] = unionarr[i-1] + dist[i];
    }
    vector<int> setarr;
    for (int i = 0; i < n; i++){
        if (unionarr[i] >= 1) setarr.push_back(i);
    }
    return setarr;
}

int dp (int n, vector<int> cur, const vector<int>& arr, vector<int>& memo){
    // base case
    if (cur.back() == n){
        return 1;
    }

    for (int i = 0; i < (int) arr.size(); i++){
        cur.push_back(cur.back() + arr[i]);
        dp(n, cur, arr, memo);
        cur.pop_back();
    }

    return 0;
}

int main(){
    int n, k; cin >> n >> k;
    vector<pair<int, int>> data (k);
    for (int i = 0; i < k; i++){
        int x, y; cin >> x >> y;
        data[i].first = x;
        data[i].second = y;
    }
    vector<int> memo;
    vector<int> cur;
    cur.push_back(1);
    cout << dp(n, cur, findset(n, k, data), memo) << endl;
    return 0;
}
