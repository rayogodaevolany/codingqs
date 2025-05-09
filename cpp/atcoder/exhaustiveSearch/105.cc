#include<iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    if (N <= 105) {
        cout << 0;
        return 0;
    }
    // how do I find this brute force solution?
    // oh like really brute force


    int count = 0, num = 0;
    // for every number up to N
    for (int i=1;i<=N;i++){
        // divide by every number up to N and see if it is divisible
        for(int j=1;j<i;j++){
        // if it is increment count
            if (i%j ==0){
                count++;
            }
        }
        if (count == 8){
            num++;
        }
    }

    // print count
    cout << num;
    
    return 0;
    }
