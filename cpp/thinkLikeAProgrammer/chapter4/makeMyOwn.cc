#include<iostream>

using namespace std;

int main(){
    // count starts at -1 since the first loop is always counted
    int N, count = -1;
    cin >> N;
    int * newArr = new int[N];
    for(int i=0;i<N;i++)cin>> newArr[i];

    bool flag = true;

    // while flag is true loop over array and keep dividing by two
    while (flag){
        // loop through arr and check divisibility of every value
        for(int i=0;i<N;i++){
            // check divisibility
            if(newArr[i] % 2 != 0){
                flag = false;
                break;
            } else {
                // make the value the divided by two value
                newArr[i] = newArr[i]/2;
            }
        }
        count++;
        
    }
    
    delete[] newArr;
    cout << count;

    return 0;
}
