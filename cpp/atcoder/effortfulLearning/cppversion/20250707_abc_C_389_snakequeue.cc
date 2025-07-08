#include <iostream>
#include <vector> 
using namespace std;
#define ll long long

// void solve(){
//     int q; cin >> q;
//     vector<ll>stack;
//     int pointer = 0;
    
//     for (int i = 0; i < q; i++){
//         int qtype; cin >> qtype;
//         if (qtype == 1){
//             int l; cin >> l;
//             // put into stack
//             stack.push_back(l);
//         } else if (qtype == 2){
//             // move index
//             pointer++;
//         } else {
//             int k; cin >> k;
//             k--;
//             ll sum = 0;
//             // sum up all those in between the start and the k value
//             for (int j = pointer; j < (k + pointer); j++){
//                 sum += stack[j];
//             }
//             cout << sum << endl;
//         }
//     }
// }

void solve(){
    int q; cin >> q;
    vector<pair<int, int>> queries(q);
    vector<ll>stack;
    vector<int> vals;

    for (int i = 0; i < q; i++){ 
        int x; cin >> x;
        queries[i].first = x;
        if (x == 1){
            int y; cin >> y;
            queries[i].second = y;
            vals.push_back(y);
        } else if (x == 3){
            int y; cin >> y;
            y--;
            queries[i].second = y;
        }
    }
    // create prefix
    int valsize = vals.size();
    vector<ll> pre(valsize);
    pre[valsize - 1] = vals[valsize - 1];
    for (int i = valsize - 2; i >= 0; i--){
        pre[i] = vals[i] + pre[i + 1];
    }

    int pointer = 0;
    for (int i = 0; i < q; i++){
        if (queries[i].first == 2) {
            // move index
            pointer++;
        } else if (queries[i].first == 3) {
            ll sum = 0;
            int k = queries[i].second;
            sum = pre[pointer] - pre[k + pointer];
            cout << sum << endl;
        }
    }

}

int main(){
    solve();
    return 0;
}
