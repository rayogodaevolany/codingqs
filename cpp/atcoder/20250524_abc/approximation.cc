#include <iostream>
using namespace std;

void solve (){
int A,B; cin >> A >> B;
float division = static_cast<float>(A)/B;
int intdiv = A/B;

float diff = division - intdiv;

if (diff > 0.5) {
    cout << intdiv + 1 << endl;
} else {
    cout << intdiv << endl;
}

// b is odd?
// 2 / 3 = 0.66
// 1/2 = 0.5 
// 1 / 4 = 0.5?
// is it hat there are no divisions by 0.5 so they will always be away from the exact equivalent?
// what the mathematical property?
// division - integer division
// check whether it is bigger than 0.5
}


int main(){
    solve();
    return 0;
}
