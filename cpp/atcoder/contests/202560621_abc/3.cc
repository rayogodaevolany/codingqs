#include <iostream>
#include <set>
#include <iterator>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    set<int> s;
    // for every query
    for (int i = 0; i < q; i++){
        // get query
        int query; cin >> query;
        // if found delete, else insert
        if (s.erase(query) == 0){
            s.insert(query);
        }


        int count = s.size();
        // go through all in the set
        for (auto it = s.begin(); it != s.end(); it++){
            // if the next is incremental
            if (*next(it) == (*it + 1)){
                count--;
            }
        }
        cout << count << endl;
    }
}

int main(){
    solve();
    return 0;
}
