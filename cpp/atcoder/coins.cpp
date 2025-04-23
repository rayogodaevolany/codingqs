#include<iostream>
using namespace std;

// find out how many ways there are to make a number X with coins A,B, and C
int main(){
    // Looking at the answers apparently this is a brute force problem
    // loop through A, B, C
    // Then multiply every value of A,B,C together. That gives every combination
    // count the amount of times that total sum because the target value.
    int A,B,C,X, res, count=0;
    cin >>A >> B >> C >> X;

    
    // loop from 0 to the number of coins for each
    for (int a = 0; a <=A; a++){
        for( int b = 0; b<=B; b++){
            for(int c = 0; c<=C; c++){
                res = a*500 + b*100 + c*50;
                if (res == X) {
                    count++;
                }
            }
        }
    }

    cout << count;
}
