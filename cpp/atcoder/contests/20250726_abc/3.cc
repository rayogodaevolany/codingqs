#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

vector<int> vectorize(int x){
    vector<int> vec;
    while (x != 0){
        int tmp = x % 10;
        vec.push_back(tmp);
        x /= 10;
    }
    return vec;
}

int main() {
    int n, k, x; cin >> n >> k >> x;
    vector<string> arr(n);
    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> vec = vectorize(x);

    string res;
    for (int i = 0; i < (int)vec.size(); i++){
        res += arr[vec[i]];
    }

    cout << res << endl;

    return 0;
}
