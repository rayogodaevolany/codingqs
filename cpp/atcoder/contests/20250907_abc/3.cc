#include <iostream>
#include <cassert>
using namespace std;

// int int int -> int
// see how many aac, abc, and acc can be made from this
int solve(int a, int b, int c){
    if ((a <= b) &&  (b <= c)){
    } else if (a >= b && b >= c) {
    } else if (a >= b && b <= c) {
    } else {
    }
    return 0;
}

int main(){
    assert(solve(1, 1, 1) == 1);
    assert(solve(0, 1, 1) == 0);
    assert(solve(2, 1, 2) == 1);
    assert(solve(3, 1, 2) == 2);
    return 0;
}


// x y z
// x <= y <= z
// x is the answer
//
// x >= y >= z 
// z is the answer
//
// x >= y <= z
// min( (max (x, z) half floor), min(x, z)) + y
//
// x <= y >= z 
// y is the answer
