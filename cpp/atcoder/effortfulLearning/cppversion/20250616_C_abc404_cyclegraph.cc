#include <iostream>
#include <vector>
using namespace std;
//I'm stuck on the concept of a cycle graph 
//what does it mean for a graph to be a cycle graph
//given a bunch of edges, then I have to see in 
//one of the permutations. it makes a full circle?


// go through each pair and then check if it connects.
// So I could look for the first then see if the second
// connects to any other
// if it does I check if the other value connects to anywhere
// keep removing pairs, if there is a pair left then not a cycle
// but it should end at the beginning node.
// if no pairs left but not at beginning node then it's not a cycle graph

void solve(){
    int n,m; cin >> n >> m;
    // m edges
    vector<pair<int, int>> arr;
    for (int i = 0; i < m; i++){
        int x, y;cin>> x >> y;
        pair<int, int> p = {x,y};
        arr.push_back(p);
    }

    int firstnode = arr[0].first;
    int currentnode = firstnode;
    bool which = true; // true is first, false is second
    int index = 0;
    while (index < m){
        if (which){
            currentnode.second;
        }
        index++;
    }

}

int main(){
    solve();
    return 0;
}
