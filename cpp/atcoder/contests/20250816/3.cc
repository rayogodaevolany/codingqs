#include <iostream>
#include <vector>
#include <map>
using namespace std;
using ll = long long;

struct posn {
    ll x;
    ll y;
};

// posn -> number
ll dist(posn p1, posn p2){
    ll x = abs(p1.x - p2.x);
    ll y = abs(p1.y - p2.y);
     
    ll res = x + y;
    res = res - min(x, y);
    return res;
}



// list of posn -> number
// the number of steps it would take for all
// posns to get to one
// find max of the lengths between posns
ll solve(int n, const vector<posn>& l){
    /* posn t0; */
    /* t0.x =2; t0.y = 3; */
    /* posn t1; */
    /* t1.x =8; t1.y=1; */
    /* cout << dist (t0, t1) << endl; */
    
    // check set for if that the value has been calculated already or not

    vector<pair<posn, posn>> s;

    ll maxposn = 0;
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (findin(s, l[i]) || findin(s, l[j])){
                maxposn = max(maxposn, dist(l[i], l[j]));
                s.push_back({l[i], l[j]});
                s.push_back({l[j], l[i]});
            }
        }
    }
    return maxposn;

}

int main() {
    int n; cin >>n;

    vector<posn> l (n);
    for (int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        l[i] = {x, y};
    }

    cout << solve(n, l) << endl;
    return 0;
}
