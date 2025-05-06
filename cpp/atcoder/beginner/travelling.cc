#include<iostream>

using namespace std;


// output Yes or No
int main() {
    // get N
    int N, t, x, y, nextTime, nextX, nextY;
    bool flag = true;
    t = x = y = 0;
    cin >> N;
    for(int i=0;i<N;i++){
        // can he move to position x, y from the past position x y
        // within t moves?
        cin >> nextTime >> nextX >> nextY;

        int withinTime = nextTime - t;
        int betweenX = abs(nextX - x);
        int betweenY = abs(nextY - y);
        int distance = betweenY + betweenX;


        if (withinTime < distance || distance % 2 != withinTime % 2){
            flag = false;
            break;
        }

                // set old times and positions
        t = nextTime; x = nextX; y=nextY;
    }

    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}
