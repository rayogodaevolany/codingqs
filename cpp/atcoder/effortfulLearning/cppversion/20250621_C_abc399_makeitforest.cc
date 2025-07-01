#include <iostream>
#include <stack>
#include <unordered_set>
#include <vector>
#include <unordered_map>
using namespace std;

void solve(){
    // dfs to find the amount of cycles
    //create a stack and loop through it.
    //create a visited and check it for loops
    //on a loop its the same as a leaf, but count it
    int n,m; cin>>n>>m;

    unordered_map<int, vector<int>> graph;
    for (int i = 0; i < m; i++){
        int x, y; cin>>x>>y;
        graph[x].push_back(y);
    }

    unordered_set<int> visited;
    stack<int> dfsstack;
    dfsstack.push(1);
    int count = 0;

    while (!dfsstack.empty()){

        // get the top off the stack
        int current = dfsstack.top();
        dfsstack.pop();

        //ask gen ai why this should be auto if it should be auto ASKASKASKASKSAKA
        for (int &it : graph[current]){
            // see if it's visited already
            if ( visited.find(it) != visited.end()){
                count++;
                break;
            }
            // insert the visited node.
            visited.insert(it);
            // keep going
            dfsstack.push(it);
        }
    }
    cout << count++ << endl;
}


int main(){
    solve();
    return 0;
}
