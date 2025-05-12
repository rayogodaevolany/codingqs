#include <iostream>
#include <vector>
using namespace std;


void test (){
    int n= 5;
    // loop 32 times
    for (int bit = 0; bit<(1<<n); bit++){
        // create a new vector every time
        vector<int> S;

        // loop 5 times
        for (int i = 0; i < n; i++){

            // add to array when the loop index and the binary bit align
            if (bit & (1 <<i)) {
                S.push_back(i);
            }
            // print out the bit
            cout << bit << ": {";
            // loop over every element in S
            for (int i = 0; i < (int)S.size(); i++) {
                // print out all the values
                cout<< S[i] << " ";
            } 
            // close curly brace
            cout << "}"<< endl;
        }
    }
}

void problem(){
    int n;
    int a[25];
    int K;

    cin >> n;
    for (int i = 0; i< n; i++) cin >> a[i];
    cin >> K;

    bool exist = false;
    // look at every possible subset
    for (int bit = 0; bit < (1 << n); bit++){

        int sum = 0;
        // look at the subset and add up all the values given in a
        // based off of the binary number
        for (int i = 0; i< n; i++){
            if (bit & (1<<i)) {
                sum += a[i];
            }
        }
        // flag for what we are looking for
        if (sum == K) exist = true; 
    }
    if (exist) cout << "Yes" << endl;
    else cout << "No" << endl;
}


void concise(){
    int N,W;
    cin >> N >> W;
    vector<int> a(N);
    for(int i=0;i<N;i++)cin >> a[i];

    bool exist = false;
    for (int bit=0;bit<(1<<N);bit++){
        int sum =0;
        for(int i=0;i<N;i++){
            if(bit&(i<<i))sum+=a[i];

        }
        if(sum==W)exist = true;
    }
    if(exist) cout << "Y" << endl;
    else cout <<"N"<<endl;
}



int main() {
    int N, W;
    cin >> N >> W;
    int a[25];
    for(int i=0;i<N;i++) cin >> a[i];


    int flag = 0;
    for(int bit=0;bit<(1<<N);bit++){
        // flag
        int sum = 0;
        for(int m=0; m<N;m++){
            if (bit & (1<<m)){
                sum += a[m];
            }
        }
        if (sum == W) {
            flag = 1;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
        
    return 0;
}
