#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void solve(){
    int n,m; cin >> n >>m;
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++){
        int x, y; cin >> x>>y;
        pair<int, int> p = {x,y};
        arr.push_back(p);
    }
    // check whether the vertex has two outs
    // check whether the vertices are all connected 
    // use a not visited, then remove the visited nodes
    stack<int> s;
    s.push()
    while (!s.empty()){
    }

    
}

int main(){
    return 0;
}

