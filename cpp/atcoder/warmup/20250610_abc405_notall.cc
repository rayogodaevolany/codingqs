#include <iostream>
#include <vector>
using namespace std;



void solve(){
    int n, m; cin >> n >> m;
    int arr[120]; 
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        arr[i]--;
    }
    int res = 0;
    int lastIndex = n - 1;
    while (true){
        bool* truths = new bool[m];
        for (int i = 0; i < m; i++){
            truths[i] = false;
        }
        for (int i = 0; i <= lastIndex; i++){
            truths[arr[i]] = true;
        }

        bool flag = false;
        for (int j = 0; j < m; j++){
            if(!truths[j]){
                flag = true;
                break;
            }
        }
        if (flag) {
            delete[] truths;
            break;
        }
        res++;
        lastIndex--;
        delete[] truths;
    }
    cout << res << endl;
}



// int comp (const void * a, const void * b){
//     const int* intA = static_cast< const int *> (a);
//     const int* intB = static_cast<const int *> (b);
//     return *intA - *intB;
// }
// void solve(){
//     int N, M; cin >> N >> M;
//     int arr[120];
//     for (int i = 0; i < N; i++) cin >> arr[i];

//     // sort arr for easier processing
//     qsort(arr, N, sizeof(int), comp);

//     int count = 0;
//     // smaller and smaller right index
//     for (int i = N - 1; i >= 0; i--){
//     //      through to M to see if it is all of them
//         for (int j = 1; j <= M; j++){
//             if (arr[j] != j){
//                 count = N - (i + 1);
//                 break;
//             }
//         }
//     }
//     cout << count << endl;


// }
//

// void solve(){
//     int n, m; cin >> n >> m;
//     vector<int> arr(n);
//     for (int i = 0; i < n; i++){
//         cin >> arr[i];
//         --arr[i];
//     }

//     // answer variable
//     int ans = 0;

//     // loop till break
//     while (true) {
//         // vector of bools
//         vector<bool> exist(m);

//         // for every value in arr, assign exist vector value to true
//         for (int i: arr) exist[i] = true;
        
//         // boolean flag
//         bool ok = false;

//         // for every value in exist
//         for (bool b: exist) {
//             // if there is a false break the loop
//             if (!b) ok = true;
//         }
//         if (ok) break;
//         // if not false then continue to count
//         ++ans;
//         // pop from the back
//         arr.pop_back();
//     }

//     cout << ans << endl;

// }

int main(){
    solve();
    return 0;
}
