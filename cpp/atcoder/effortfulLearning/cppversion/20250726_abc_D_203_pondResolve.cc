#include <iostream>
using namespace std;
#define GRID 805
typedef int GridRow[GRID];

// int -> int
// calculate which element is considered the median.
// given 4 expect 9, 9th largest value is the median
int median(int k){
    return ((k*k/2) + 1);
}

// int int grid -> grid 
// Create a prefix sum matrix from a given grid
// where each individual cell is boolean of whether that cell
// is bigger than the given value x.
// given 3, 2 and a grid
//  1 2
//  3 4
//  expect
//  0 0
//  0 1
const GridRow* prefix(int x, int n, const int grid[GRID][GRID]){
    static int prematrix [GRID][GRID];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            prematrix[i][j] = 0;
        }}
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            prematrix[i+1][j+1] = prematrix[i+1][j]
                + prematrix[i][j+1]
                - prematrix[i][j];
            if (grid[i][j] > x){
                prematrix[i+1][j+1]++;
            }
        }
    }
    return prematrix;
}


// actual grid
//  4 0 10
//  0 0 7
//  15 9 8

// before converting to prefix
//  0 0 0 0
//  0 1 0 1
//  0 0 0 1
//  0 1 1 1


// int int grid -> bool
// take a prefix sum matrix and check whether there are 
// k by k squares with a median larger than a given value x.
// -1 refers to no smaller median found
// given 2, 3, a grid:
//  0 0 0 0
//  0 1 1 2
//  0 0 1 3
//  0 2 3 6
//  expect true
// given 2, 3, a grid:
//  0 0 0 0
//  0 1 2 3 
//  0 2 4 6 
//  0 3 6 9 
//  expect false

bool smallerMedian(int k, int n, const int grid[GRID][GRID]){
    for (int i = 0; i < (n - k) + 1; i++){
        for (int j = 0; j < (n - k) + 1; j++){
            int res = grid[i+k][j+k]
                - grid[i][j+k]
                - grid[i+k][j]
                + grid[i][j];
            if (res < median(k)){
                return true;
            }
        }
    }
    return false;
}


// int int grid -> int
// Binary search through all possible median values and find the smallest.
// given 2, 3
//  4 5 10
//  0 5 7
//  15 9 8
//  expect 
//  5 
int binarysearch(int k, int n, const int grid[GRID][GRID]){
    int high = 1e9;
    int low = -1;
    while (low + 1 < high){
        int middle = ((high - low) / 2) + low;
        if (smallerMedian(k, n, prefix( middle, n, grid))){
            high = middle;
        } else {
            low = middle;
        }
    }
    return high;
}

void solve(){
    int n, k; cin >> n >> k;
    int grid[GRID][GRID];
    
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cin >> grid[i][j];
        }
    }
    cout << binarysearch(k,n,grid) << endl;
    
}

#ifdef LOCAL_TESTING

#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
#define tc TEST_CASE
#define check CHECK

tc("stub test"){
    check(true);
}

tc("prefix"){
    int n = 2;
    int testgrid[GRID][GRID];
    testgrid[0][0] = 1;
    testgrid[0][1] = 2;
    testgrid[1][0] = 3;
    testgrid[1][1] = 4;

   const GridRow* res = prefix(3, n, testgrid);
   check(res[2][2] == 1);
   check(res[1][1] == 0);
   check(res[2][1] == 0);
   check(res[1][2] == 0);
}

tc("smallerMedian true"){
    int n = 3, k = 2;
    int testgrid[GRID][GRID];
    testgrid[0][0] = 0;
    testgrid[0][1] = 0;
    testgrid[0][2] = 0;
    testgrid[0][3] = 0;
    testgrid[1][0] = 0;
    testgrid[2][0] = 0;
    testgrid[3][0] = 0;

    testgrid[1][1] = 1;
    testgrid[1][2] = 1;
    testgrid[1][3] = 2;
    testgrid[2][1] = 0;
    testgrid[2][2] = 1;
    testgrid[2][3] = 3;
    testgrid[3][1] = 2;
    testgrid[3][2] = 3;
    testgrid[3][3] = 6;

    check(smallerMedian(k,n,testgrid) == true);
}

tc("smallerMedian false"){
    int n = 3, k = 2;
    int testgrid[GRID][GRID];
    testgrid[0][0] = 0;
    testgrid[0][1] = 0;
    testgrid[0][2] = 0;
    testgrid[0][3] = 0;
    testgrid[1][0] = 0;
    testgrid[2][0] = 0;
    testgrid[3][0] = 0;

    testgrid[1][1] = 1;
    testgrid[1][2] = 2;
    testgrid[1][3] = 3;
    testgrid[2][1] = 2;
    testgrid[2][2] = 4;
    testgrid[2][3] = 6;
    testgrid[3][1] = 3;
    testgrid[3][2] = 6;
    testgrid[3][3] = 9;

    check(smallerMedian(k,n,testgrid) == false);
}


tc("binarySearchofficial"){
    int testgrid[GRID][GRID];
    testgrid[0][0] = 1;
    testgrid[0][1] = 7;
    testgrid[0][2] = 0;
    testgrid[1][0] = 5;
    testgrid[1][1] = 8;
    testgrid[1][2] = 11;
    testgrid[2][0] = 10;
    testgrid[2][1] = 4;
    testgrid[2][2] = 2;
    int n = 3, k =2;

    check(binarysearch(k,n,testgrid) == 4);
}
tc("binarySearch"){
    int testgrid[GRID][GRID];
    testgrid[0][0] = 4;
    testgrid[0][1] = 5;
    testgrid[0][2] = 10;
    testgrid[1][0] = 0;
    testgrid[1][1] = 5;
    testgrid[1][2] = 7;
    testgrid[2][0] = 15;
    testgrid[2][1] = 9;
    testgrid[2][2] = 8;
    int n = 3, k =2;

    check(binarysearch(k,n,testgrid) == 4);
}

int main(){
    doctest::Context context;
    int test_result = context.run();
    if(context.shouldExit()) return test_result;
    return 0;
}

#else

int main() {
    solve();
    return 0;
}

#endif
