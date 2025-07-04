#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    vector<int> location(n + 1);
    unordered_map<int, vector<int>> hash(n);
    for (int i = 1; i <= n; i++){
        location[i] = i;
        hash[i].push_back(i);
    }

    int count = 0;
    for (int i = 0; i < q; i++){
        int qtype; cin >> qtype;
        if (qtype == 1 ){
            int p,h; cin >> p >> h;

            //find where p is and erase it from the hash
            vector<int>::iterator it;
            it = hash[location[p]].begin();
            while (it != hash[location[p]].end()){
                if (*it == p){
                    // needs to be optimized
                    it = hash[location[p]].erase(it);
                    break;
                }
                it++;
            }

            // after removing the pigeon, if the nest is 1 then decrement
            if ((int)hash[location[p]].size() == 1){
                count--;
            }
            
            // if the pigeon is moved to a nest with 1 then increment
            if ((int)hash[h].size() == 1){
                count++;
            }

            // place p in the right hash location
            hash[h].push_back(p);
            location[p] = h;


        } else if (qtype == 2){
            // output count
            cout << count << endl;
        }
    }

}

int main(){
    solve();
    return 0;
}
