#include <iostream>
#include <utility>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

double distance(pair<int, int> r, pair<int, int> l){
    return sqrt(pow((r.first - l.first), 2) + (pow(r.second - l.second, 2)));
}
// list of coordinates -> average
// get the average distance between all of these coordinates
void solve(){
    int n; cin >> n;
    vector<pair<int, int>> arr(n);
    vector<int> order(n);
    // create an ordered array from 0 to n -1;
    for (int i = 0; i < n; i++) order[i] = i;

    // in the arr of pairs put in the coordinates
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        arr[i].first = x;
        arr[i].second = y;
    }

    double sum = 0;
    double count = 0;
    // for every permutation of array order
    do {
        for (int i = 0; i < (n -1); i++){
            sum += distance(arr[order[i+1]], arr[order[i]]);
        }
        count++;
    } while (next_permutation(order.begin(), order.end()));

    double average = sum / count;
    cout << setprecision(10) << average << endl;
}

int main(){
    solve();
    return 0;
}
