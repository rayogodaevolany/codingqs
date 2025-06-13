#include <iostream>
using namespace std;

int main(){
    int N, S; cin >> N >> S;
    int arr[123];
    arr[0] = 0;
    for (int i = 1; i < N + 1; i++ ) cin >>arr[i]; 

    double timeawake = S + 0.5;
    

    //first one
    // loop over array
    for (int i = 1; i < N + 1; i++){
        double interval = arr[i] - arr[i - 1];
        if (interval > timeawake){
            cout << "No"<<endl;
            return 0;
        }
    }
    cout << "Yes" << endl;


    return 0;
}
