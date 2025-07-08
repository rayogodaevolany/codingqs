#include <iostream>
#include <list>
#define ll long long

using namespace std;
void solve(){
    int q; cin >> q;
    list<ll> val;
    list<ll> count;
    for (int i = 0; i < q; i++){
        int querytype; cin >> querytype;

        if (querytype == 1){
            ll c, x; cin >> c >> x;
            count.push_back(c);
            val.push_back(x);
        } else {
            int k; cin >> k;
            ll sum = 0;
            while (k != 0){
                if (k >= count.front()){
                    sum += (ll)count.front() * val.front();
                    k -= count.front();
                    count.pop_front();
                    val.pop_front();
                } else{
                    sum = (ll)sum + (k * val.front());
                    count.front() -= k;
                    k = 0;
                }
            }
            cout << sum << endl;
        }
    }
}

int main(){
    solve();
    return 0;
}
