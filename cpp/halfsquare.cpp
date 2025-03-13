#include <iostream>
using namespace std;

int main () {
    int num2 = 8;

    for(int i = 0; i < num2; i++){
        for(int t = 0; t < 4 - abs( 4 - i); t++){
            cout << "#";
            }
        cout << "\n";
    }

    int num = 5;

    for(int i = 0; i < num; i++){
        for(int t = 0; t < 5 - i; t++){
            cout << "#";
            }
        cout << "\n";
    }

 
}
