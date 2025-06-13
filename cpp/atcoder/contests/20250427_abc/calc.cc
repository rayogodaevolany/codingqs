#include <iostream>
using namespace std;


bool inrange( int product, int K){
    int count = 0;
    while (product != 0){
        product /= 10;
        count++;
    }
    if (count > K ){
        return true;
    } 
    return false;
}

int main(){

    // N operations K digit display
    int N, K; cin >> N >> K;
    // 
    int arr[110];

    for (int i = 0; i < N; i++) cin >> arr[i];

    int product = 1;
    for (int i = 0; i< N; i++){
        // for every num mult by next val
        product *= arr[i];

        if (inrange(product, K)) {
            product = 1;
        }
    }

    cout << product << endl;
    
    return 0;
}
