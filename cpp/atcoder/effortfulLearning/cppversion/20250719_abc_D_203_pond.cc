#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            cin >> matrix[i][j];
        }
    }
    int mediansize = floor(pow(k, 2)/2) + 1;

    int upper = 1e9;
    int lower = -1;
    int middle = (1e9 /2);
    int count = 0;
    while ( count <= 50){
        count++;
        bool less = false;
        vector<vector<int>> gtmedian(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                if ( matrix[i][j] > middle){
                    gtmedian[i][j] = 1;
                } else {
                    gtmedian[i][j] = 0;
                }
            }
        }

        vector<vector<int>> psums(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                psums[i][j] = 
                    (psums[i - 1][j] + psums[i][j-1])
                    - psums[i - 1][j - 1] 
                    + gtmedian[i][j];
            }
        }
        
        for (int i = 1; i <= (n - k); i++){
            for (int j = 1; j <= (n - k); j++){
                int btmrighti = i + k - 1;
                int btmrightj = j + k - 1;
                int numofgtmed = 
                    psums[btmrighti][btmrightj]
                    - psums[i - 1][btmrightj] 
                    - psums[btmrighti][j - 1] 
                    + psums[i][j];
                if (numofgtmed < (mediansize - 1)){
                    upper = middle;
                    less = true;
                    break;
                }
            }
        }
        if (!less){
            lower = middle;
        }
        middle = (upper - lower)/2 + lower;
    }
}

int main (){
    solve();
    return 0;
}
