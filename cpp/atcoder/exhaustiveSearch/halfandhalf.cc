#include<iostream>
using namespace std;

int main(){
    int A,B,C,X,Y;
    cin>> A >> B >> C >> X >> Y;

    int cost, minimum =  A*X + B*Y;
    //
    // I looked at the answer and it seems to somehow relate to the idea that 
    // the ab set is more important for this?
    //
    // since this can be 100000 this needs to be optimized
    int N = X+Y;
    // the code runs 10**10 times which is roughly 10 secs
    for (int a =0; a<N; a++){
        for (int b=0; b < N-a; b++){
            // the last for loop can run with ab
            // being dependent on a and b
            int ab = N -a - b;
                // if the half pizzas and normal pizza are
                // equal to or greater than the necessary amount
                if ( 
                    ab/2 + a >= X 
                    && ab/2 + b >= Y
                ){
                    // get cost of pizzas
                    cost = A*a+B*b+C*ab;
                    // check if it is bigger than the minimum
                    if (minimum > cost) {
                        minimum = cost;
                }
            }
        }
    }

    cout << minimum;
    return 0;
}
