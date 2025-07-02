#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// void solve(){
//     int n; cin >> n;
//     unordered_map<int, int> hash;
//     vector<int> arr(n);
//     vector<int> qs(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//         arr[i]--;
//     }

//     for (int i = 0; i < n; i++){
//         int x; cin >> x;
//         qs[i] = x;
//         hash[x] = i;
//     }

//     for (int i = 1; i <= n; i++){
//         cout << qs[arr[hash[i]]] << " ";
//     }
//     cout << endl;
// }

int getn(){
    int n; cin >> n;

    return n;
}

vector<int> getps(int n){
    vector <int> ps(n);
    for (int i = 0; i < n; i++){
        cin >> ps[i];
        ps[i]--;
    }
    return ps;
}
vector<int> getqs(int n){
    vector <int> qs(n);
    for (int i = 0; i < n; i++){
        cin >> qs[i];
    }
    return qs;
}

unordered_map<int, int> makeHash( int n, vector<int> qs){
    unordered_map <int, int> hash(n);
    for (int i = 0; i < n; i++){
        hash[qs[i]] = i;
    }
    return hash;
}

void solve(int n,vector<int>ps, vector<int> qs, unordered_map<int, int> hash){
    for (int i = 1; i <= n; i++){
        cout << qs[ps[hash[i]]] << " ";
    }
    cout << endl;
}


int main(){
    int n = getn();
    vector<int> ps = getps(n);
    vector<int> qs = getqs(n);
    unordered_map<int, int> hash = makeHash(n,qs);
    solve(n, ps, qs, makeHash(n, qs));
    return 0;
}
