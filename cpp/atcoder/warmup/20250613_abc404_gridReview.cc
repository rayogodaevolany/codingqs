#include <iostream>
using namespace std;

// count the difference between the grids
int countdiff(vector<string> S, vector<string> T){
    // size of grids
    int N = S.size();
    
    int ans = 0;
    // loop over every row
    for (int i = 0; i < N; i++) {
        // loop over every columns
        for ( int j = 0; j < N; j++){
            if (S[i][j]!=T[i][j]){
                //if the row isn't equivalent count
                ans++;
            }

        }
    }
    return ans;
}


// rotates the grid
vector<string> right_rotation(vector<string> S){
    // size of grid
    int N = S.size();
    // N strings instantiated to N dots in each string
    // basically an n x n grid
    vector<string> ret(N, string(N, '.'));
    for (int i = 0; i < N; i++) for (int j = 0; j < N; j++){
        // fill each box in the new grid
        // with rotation
        ret[i][j] = S[N-1-j][i];
    }
}

