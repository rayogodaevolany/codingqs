#include <iostream>
#include <cmath>
using namespace std;

void solve(){
    int n; cin >> n;
    // find the upper limits of a and b
    int count = 0;
    bool ok = false;

    for (int m = 1; m <= n; m++){
        int A = log2(m);
        int B = sqrt(m);
        for (int i = 1; i <= A; i++){
            for (int j = 1; j <= B; j++){
                if (m == (pow(2,i)*pow(j,2))){
                    ok = true;
                    break;
                }
            }
        }
        if (ok){
            count++;
            ok = false;
        }
    }
    cout << count << endl;
}

int main(){
    solve();
    return 0;
}
