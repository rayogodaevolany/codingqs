#include <iostream>
using namespace std;

int N;
int A[20];
// two by two matrices where x[i][j],
// i is the person who is giving the testimony
// j is the person who is being judged
// y is similar but j is the judgement
int x[20][20];
int y[20][20];

int counter(int x) {
    // base case
    if(x == 0) return 0;
    // if the last bit is one add one. Recurse.
    return counter(x>>1) + (x & 1);
}

void solve(){
    cin >> N;
    // store input in arrays
    for (int i = 1; i <= N; i++){
        cin >> A[i];
        // for the amount of testimonies of each person
        for (int j = 1; j <= A[i]; j++){
            // x[j] who, y[j] honestOrUnkind
            cin >> x[i][j] >> y[i][j];
        }
    }

    //flag
    int ans = 0; 
    // loop over every possible bit
    for (int bits = 1; bits < (1 << N); bits++){
        bool ok = true;
        // loop for every bit
        for (int i = 1; i <= N; i++){
            // if the bit shows the person is unkind
            if (!(bits & (1 << (i-1)))) continue;
            // for the amount of judgements the person gives
            for (int j = 1; j <= A[i]; j++){
                // check whether current bit assumes the person under question
                // is honest or not
                // if the check on the binary string and the verdict of this
                // current person are different then set flag to false
                if(((bits >> (x[i][j]-1)) & 1)^y[i][j]) ok = false;
            }
        }
        // if flag is valid, then take the max of ans and the count
        if(ok) ans = max(ans, counter(bits));
    }
    // outpupt ans
    cout << ans << endl;
    return;

}

int main(){
    solve();
    return 0;
}


