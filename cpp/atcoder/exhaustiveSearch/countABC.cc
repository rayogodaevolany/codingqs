#include<iostream>
using namespace std;

int main(){

    int N;
    cin >> N;
   
    char* x = new char[N];
    for(int i = 0;i<N;i++){
        cin >> x[i];
    }

    int count = 0;
    // look for abc and if found skip to next
    // loop over x
    for (int i=0;i<N;){
        // check if a b c are the next three
        if (x[i] == 'A'&& x[i+1] == 'B' && x[i+2] == 'C'){
        // count 
            count++;
        // jump to after the abc
            i += 3;
        } else {
        // else go to next index
            i++;
        }
     }
    cout << count;

    delete[] x;
    return 0;
}
