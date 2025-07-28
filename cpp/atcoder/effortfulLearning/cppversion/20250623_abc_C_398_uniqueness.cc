#include <iostream>
#include <unordered_map>
#include <queue>
#include <stack>
using namespace std;

void solve(){
    // hashmaps
    int n; cin >> n;
    unordered_map<int, int> h;
    priority_queue<int> pq;
    priority_queue<int> invalid;
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        h[x]++;
        if(h[x] == 1){
            // i need a set of valids that become unvalid, priority queue
            pq.push(x);
        } else if (h[x] == 2){
            invalid.push(x);
        }
    }
    while (invalid.top() == pq.top()){
        pq.pop();
        invalid.pop();
    }
    cout << pq.top() << endl;
}

int main(){
    solve();
    return 0;
}
