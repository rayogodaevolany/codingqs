#include <iostream>
using namespace std;

struct d {
    long n;
    long k;
    vector<int> a;
};
// d is a structure
// n is the number of ints in a
// k is the value that has to be compared

// int int array -> d
d getInput(){
    d data;
    cin >> data.n;
    cin >> data.k;
    for (int i = 0; i < data.n; i++){
        int x; cin >> x;
        data.a.push_back(x);
    }
    return data;
}

//d -> long
// count how many subarrays from the given index equals data.k
long checkfori (int i, d data){
    long count = 0;
    long res = 0;
    for (int j = i; j < data.n; j++){
        res += data.a[j];
        if (res >= data.k) {
            count++;
        }
    }
    return count;
}

// d -> long
// count how often the sum of a contiguous subarray 
// in data.a is greater than data.k
long solve(d data){
    long count = 0;
    for (int i = 0; i < data.n; i++){
        count += checkfori (i, data);
    }
    return count;
}

// d -> long
// count times the sum of a contiguous subarray
// in data.a is greater than data.k
long optsolve(d data){
    // int l = 0, r = 1;
    // long res = 0;
    // long count = 0;
    // while (r < data.n - 1){
    //     if (res >= data.k){
    //         count++;
    //         res -= data.a[l];
    //         l++;
    //     } else {
    //         res += data.a[r];
    //         r++;
    //     }
    // }
    // return count;

    long count = 0;
    long sum = 0;
    int r = 0;

    for (int l = 0; l < data.n; l++) {
        // move r forward to make sum >= k
        while (r < data.n && sum < data.k) {
            sum += data.a[r];
            r++;
        }
        if (sum >= data.k) {
            count += (data.n - r + 1);
        }
        sum -= data.a[l];
    }
    return count;
}

#ifdef LOCAL_TESTING

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#define tc TEST_CASE
#define check CHECK

tc("stub test"){
    check(true);
}

tc("solve") {
    d t1 = {4, 10, {6, 1, 2, 7}};
    check (solve(t1) == 2);

    d t2 = {3, 5, {3,3,3}};
    check (solve(t2) == 3);

    d t3 = {1, 2, {1}};
    check (solve(t3) == 0);

    d t4 = {10, 53462,
        {103, 35322, 232, 342, 21099, 90000, 18843, 9010, 35221, 19352}};
    check (solve (t4) == 36);

    d t5 = {4, 2, {5, 1, 2, 19}};
    check (solve(t5) == (4 + 2 + 1 + 1 + 1));
}

tc("optsolve") {
    d t1 = {4, 10, {6, 1, 2, 7}};
    check (optsolve(t1) == 2);

    d t2 = {3, 5, {3,3,3}};
    check (optsolve(t2) == 3);

    d t3 = {1, 2, {1}};
    check (optsolve(t3) == 0);

    d t4 = {10, 53462,
        {103, 35322, 232, 342, 21099, 90000, 18843, 9010, 35221, 19352}};
    check (optsolve (t4) == 36);
   
    d t5 = {4, 2, {5, 1, 2, 19}};
    check (optsolve(t5) == (4 + 2 + 1 + 1 + 1));

}

tc("checkfori"){
    d t1 = {4, 10, {6, 1, 2, 7}};
    check (checkfori(1, t1) == 1);

    d t2 = {3, 5, {3,3,3}};
    check (checkfori(2, t2) == 0);

    d t3 = {1, 2, {1}};
    check (checkfori(0, t3) == 0);
}

int main(){
    doctest::Context context;
    int test_result = context.run();
    if(context.shouldExit()) return test_result;
    return 0;
}

#else

int main() {
    return 0;
}

#endif
