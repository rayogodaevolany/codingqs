#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int N, M; cin >> N >> M;
    // create a vector for info 
    vector<vector<int>> arr(M);

    for (int i = 0; i < M; i++){
        int L, R; cin >> L >> R;
        arr[i].push_back(L);
        arr[i].push_back(R);
    }

    // create binary num
    int bits = 1 << (N + 1);

    for (int i = 0; i < M; i++){
        int x = arr[i][0];
        int y = arr[i][1];
        while (x <= y){
            bits |= (1 << x);
            x++;
        }
    }



    int res = bits + 1;
    if (res != (N ^ 2)){
        cout << 0;
        return 0;
    }

    // bit brutforce

    int mincount = 0;
    // for every binary value
    for (int binary = 0; binary < 1 << (M + 1); binary++){
        int countbits =  M - __builtin_popcount(binary); 
        // check every one of those bits
        int bits = 1 << (N+1);
        for (int i = 0; i < M; i++){
                int x = arr[i][0];
                int y = arr[i][1];
                while (x <= y){
                    bits |= (1 << x);
                    x++;
                }
        }
        int res = bits + 1;
        if (res != (N ^ 2)){
            mincount = min(mincount, countbits);
        }

    }
    cout << mincount <<endl;

    return 0;
}
