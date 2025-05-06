#include<iostream>
using namespace std;
// Find the sum of the integers between 1 and N (inclusive), whose sum of digits written in base 10 is between A and B (inclusive).

// routine that returns sum of digits
// input: digit, output int
int sumDigits( int digits){
    int res = 0;
    // while digit is not zero
    while (digits != 0){
        // mod by ten then add mod to res
        res += digits % 10;
        // digit is now div by ten (floor to zero)
        digits = digits / 10;
    }
    return res;
}



int main(){
    int N, A, B, res = 0;

    // get n a b
    cin >> N >> A >> B;

    // loop over every int from 1 to N
    for(int i =1; i <=N; i++){
        // Find sum of digits
        int sum = sumDigits(i);
        // check that the sum of digit is between A and B
        if ( A <= sum && sum <= B){
            // add to res;
            res += i;
        }
    }

    cout << res;
    return 0;
}
