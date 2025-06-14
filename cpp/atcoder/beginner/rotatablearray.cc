#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void solve(){
    int n, q; cin >> n >> q;
    queue<int> qu;
    vector<int> arr;
    for (int i = 1; i <= n; i++){
        qu.push(i);
        arr.push_back(i);
    }

    for (int i = 0; i < q; i++){
        int qtype,x,p,k; cin >> qtype;
        if (qtype == 1){
            cin >> p >> x;
            arr[p - 1] = x;
            while(!qu.empty()){
                qu.pop();
            }
            for (int j = 0; j < static_cast<int>(arr.size()); j++){
                qu.push(arr[j]);
            }
        } else if (qtype == 2){
            cin >> p;
            cout << arr[p - 1] << endl;
        } else {
            cin >> k;
            for (int j = 0; j < k; j++){
                int fr = qu.front();
                qu.pop();
                qu.push(fr);
            }
            queue<int> temp(qu);
            int index = 0;
            while(!temp.empty()){
                arr[index] = temp.front();
                temp.pop();
                index++;
            }
        }
    }
}

int main(){
    solve();
    return 0;
}
