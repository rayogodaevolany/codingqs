#include<iostream>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>> A >> B >> C >> X >> Y;

    int cost, minimum =  A*X + B*Y;
    //
    // I looked at the answer and it seems to somehow relate to the idea that 
    // the half set should be the one we loop over

    // loop until twice the total amount of pizzas 
    for (int half = 0; half <= (X+Y)*2; half++){
        // a and b are derived from half
        //
        // half is 0 to X+Y doubled
        // but there can be too many half pizzas and 
        // the number can become negative

        // a is set to X
        int a = 0, b = 0;
        // if half pizzas are more than X
        if ( half/2 < X){
            a = X - (half/2);
        }
        if ( half/2 < Y){
            b = Y - (half/2);
        }

        // get cost of pizzas
        cost = A*a+B*b+C*half;

        // check if it is bigger than the minimum
        if (minimum > cost) {
            minimum = cost;
        }

    }

    cout << minimum;
    return 0;
}
