#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// 1-index
// you don't need to change the list of numbers that are being summed
// if it is smaller, then swap it out from the list
//
void solve (int n, int q, vector<ll> a, vector<ll> b, vector<vector<int>> queries){
    ll sum = 0;
    for (int i = 0; i < n; i++){
        sum+= min(a[i], b[i]);
    }


    // sum queries
    for (int i = 0; i < q; i++){

        ll symbol = queries[i][0];
        ll index = queries[i][1];
        ll replace = queries[i][2];
        sum -= min(a[index], b[index]);

        if (symbol == 0){
            a[index] = replace;
        } else {
            b[index] = replace;
        }
        sum += min(a[index], b[index]);
        cout << sum << endl;
    }

} 

int main() {
   int n, q ; cin >> n >> q; 
   vector<ll>a(n);
   vector<ll>b(n);
   for (int i = 0; i < n; i++) cin >> a[i];
   for (int i = 0; i < n; i++) cin >> b[i];
   vector<vector<int>> queries(q, vector<int>(3));
   for (int i = 0; i < q; i++){
       char aorb; cin >> aorb;
       if (aorb == 'A') queries[i][0] = 0;
       else queries[i][0] = 1;
       int index; cin >> index;
       index--;
       queries[i][1] = index;
       cin >> queries[i][2];
   }
   solve(n, q, a, b, queries);

   return 0; 
}
