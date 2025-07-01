#include <iostream>
#include <unordered_map>
#include <vector>
#include <stack>
using namespace std;

void solve(){
    // the minimum amount of edges it needs to be a single component?
    // so dfs through it without counting visited?
    int n,m; cin >> n >> m;
    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        graph[u].push_back(v);
    }

    stack <int> dfs;
    int count = 0;
    dfs.push(graph[1][0]);
    unordered_map <int, int> visited;
    while (!dfs.empty()){
        int cur = dfs.top();
        dfs.pop();

        for (int i = 0; i < (int)graph[cur].size(); i++){
            if (visited[graph[cur][i]] > 0){
                continue;
            } else {
                visited[graph[cur][i]]++;
                dfs.push(graph[cur][i]);
            }
        }
        count++;
    }
    cout << m - count << endl;
}

int main(){
    solve();
    return 0;
}
