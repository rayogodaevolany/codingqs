#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    // use brute force to break this problem open
    // loop over 1 to 9 twice and see if it can equal the value
    for (int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            if (i*j == N) {
                cout << "Yes";
                return 0;
            }

        }
    }
    cout << "No";
    return 0;
}
