#include<iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int diameter [110];
    for(int i=0;i<N;i++){
        cin>>diameter[i];
    }

    //create bucket 
    int bucket[110] = {0};
    // label the indexes of the bucket with the amount of 
    // times the indexes show up in the diameters array
    for(int i=0;i<N;i++){
        bucket[diameter[i]]++;
    }
    //if the number is more than one, count it 
    int count=0;
    for (int i=1;i<=100;i++){
        if (bucket[i] > 0){
            count++;
        }
    }
    cout << count;
    return 0;
}
