#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

// get the maximum sum
void solve(){
    //take the array split at the beginner and loop through the whole thing.
    //keep hashmap of everything and count the occurences
    // when duped in the second and new to the first increase the count
    //


    unordered_map <int, int> hashend;
    unordered_map <int, int> hashfront;
    int n; cin>> n;
    vector<int> vec;
    for (int i = 0; i < n; i++){
        int a; cin >>a;
        vec.push_back(a);
        hashend[a]++;
    }
    int count = hashend.size();
    for (int i = 0; i < n; i++){
        hashfront[vec[i]]++;
        hashend[vec[i]]--;
        if (hashend[vec[i]] == 0){
            hashend.erase(vec[i]);
        }
        count = max(count,(int)(hashfront.size() + hashend.size()));

    }
    cout << count << endl;
}

int main(){
    solve();
    return 0;
}
