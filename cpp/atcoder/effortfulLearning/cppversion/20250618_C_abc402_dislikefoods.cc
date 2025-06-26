#include <iostream>
#include <vector>
#include <set>
using namespace std;

void solve(){
    int n,m; cin >> n >> m;
    vector<set<int>> s(m);
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        for (int j = 0; j < x; j++){
            int y; cin >> y;
            s[i].insert(y);
        }
    }
    for (int i = 0; i < n; i++){
        int b; cin>>b;
        // go through each one, check if after removal it is empty if so then add to count then print
        int count = 0;
        // for every dish
        for (int j = 0; j < m; j++){
            if(!s[j].empty()){
                auto it = s[j].find(b);
                if (it != s[j].end()){
                    s[j].erase(b);
                }
            }
            if (s[j].empty()){
                count++;
            }
        }
        cout << count << endl;
    }

}

int main(){
    solve();
    return 0;
}
