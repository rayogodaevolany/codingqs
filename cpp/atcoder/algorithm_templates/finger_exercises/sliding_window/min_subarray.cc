#include <iostream>
using namespace std;

// array-of-nums positive int -> number
// find the minimum subarray length that is greater than or equal to a target
// given {1, 1} 1 expect 1
// given {2, 2} 5 expect 0
// given {1, 2, 3, 1} 4 expect 2
int solve(vector<int> arr, int target){
    int n = (int) arr.size();
    int window_sum = 0;
    for (int i = 0; i < n; i++){
        window_sum += arr[i];
        if(i >= target -1) {
            window_sum -= arr[i - target + 1];
        }
    }
    return window_sum;
}
// ==================================================

#ifdef LOCAL_TESTING

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#define tc TEST_CASE
#define check CHECK

tc("stub test"){
    check(true);
}
tc("solve") {
    check(solve({1,1}, 1) == 1);
    check(solve({2,2}, 5) == 0);
    check(solve({1, 2, 3, 1}, 4) == 2);
}

int main(){
    doctest::Context context;
    int test_result = context.run();
    if(context.shouldExit()) return test_result;
    return 0;
}

#else
// ==================================================

int main() {
    return 0;
}

#endif
