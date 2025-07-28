#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

void solve(){
    int n,m,q; cin >>n>>m>>q;
    // unordered set and binary values
    // keep track of ons and offs
    unordered_map <int,int>u;
    for (int i = 1; i <= n; i++){
        u[i] = 0;
    }
    vector<vector<int>> queries;

    for (int i = 0; i < q; i++){
        vector<int> query(3);
        cin >> query[0] >> query[1];
        // fix to zero indexing
        query[1]--;
        if (query[0] != 2) {
            cin >> query[2];
            // fix to zero indexing
            query[2]--;
        }
        queries.push_back(query);
    }

    for (int i = 0; i < q; i++){
        // if the first one is 1
        if (queries[i][0] == 1){
            // find in hashmap the user's permissions
            // toggle the correct place
            u[queries[i][1]] |= 1<<(queries[i][2]);
        } else if (queries[i][0] == 2){
            // find in the hashmap the user's permissions
            // toggle the whole thing
            u[queries[i][1]] = (1 << (m)) - 1;
        } else {
            // find the hashmap and see if the place asked for is toggled
            if(u[queries[i][1]] & (1<<queries[i][2])){
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
