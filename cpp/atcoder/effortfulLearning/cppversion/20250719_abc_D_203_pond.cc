#include <iostream>
#include <vector>

#define N 805
#define MAX_A 1000000000
#define rep(i, n) for(int i = 0; i < n; ++i)

using namespace std;

void solve(){
    int n,k; cin >> n >> k;
    vector<vector<int>> matrix(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> matrix[i][j];
        }
    }
    int mediansize = (k*k/2) + 1;

    int upper = MAX_A;
    int lower = -1;
    int middle;
    int count = 0;
    while ((lower + 1) < upper){
        middle = (upper - lower)/2 + lower;
        count++;
        bool less = false;
        vector<vector<int>> psums(n + 1, vector<int>(n + 1, 0));

        // extra one for the first row which is just zero
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                psums[i + 1][j + 1] = 
                    (psums[i][j + 1] + psums[i + 1][j])
                    - psums[i][j];
                if (matrix[i][j] > middle) psums[i + 1][j+1]++;
            }
        }
        
        for (int i = 0; i < n - k + 1; i++){
            for (int j = 0; j < n - k + 1; j++){
                int numofgtmed = 
                    psums[i + k][j + k]
                    - psums[i + k][j] 
                    - psums[i][j + k] 
                    + psums[i][j];

                if (numofgtmed < (mediansize)){
                    less = true;
                }
            }
        }
        if (less) {
            upper = middle;
        } else {
            lower = middle;
        }
    }
    cout << upper << endl;
}

int main (){
    solve();
    return 0;
}

void solution (){
	int n, k, lim;
	int a[N][N];
	int s[N][N];
    // initialize to 0
	rep(i, N) {
		s[i][0] = 0;
		s[0][i] = 0;
	}

	int ng = -1;
	int ok = MAX_A;
	int mid;
	bool ext;

    // get n and k
	cin >> n >> k;

    // median
	lim = ((k*k) / 2) + 1;

    // fill the grid
	rep(i, n) {
		rep(j, n)cin >> a[i][j];
	}

    // while low + 1 is less than high
	while ((ng + 1) < ok) {
        // low + high div 2
		mid = (ng + ok) / 2;
		rep(i, n) {
			rep(j, n) {
                // prefix matrix sums
				s[i + 1][j + 1] = s[i + 1][j] + s[i][j + 1] - s[i][j];

                // 1s and 0s, if greater than mid
				if (a[i][j] > mid)s[i + 1][j + 1]++;
			}
		}
		ext = false;
		rep(i, n - k + 1) {
			rep(j, n - k + 1) {
				if ((s[i + k][j + k] + s[i][j] - s[i][j + k] - s[i + k][j]) < lim){
                    ext = true;
                }
			}
		}
		if (ext) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}
