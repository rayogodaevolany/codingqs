#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

double distance(pair<int, int> r, pair<int, int> l){
    return sqrt(pow((r.first - l.first), 2) + (pow(r.second - l.second, 2)));
}

void solve(){
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> order(n);
    for (int i = 0; i < n; i++) order[i] = i;
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr[i].first = x;
        arr[i].second = y;
    }
    double sum = 0;
    double count = 0;
    do {
        for (int i = 0; i < n; i++){
            sum += distance(arr[order[i]], arr[order[i+1]]);
        }
        count++;
    } while (next_permutation(order.begin(), order.end()));

    double average = sum / count;
    cout << average << endl;
}

int main(){
    solve();
    return 0;
}
