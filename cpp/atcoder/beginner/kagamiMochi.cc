#include<iostream>
#include<algorithm>
using namespace std;

int main() {
    int N;
    cin >> N;
    int diameter [110];
    for(int i=0;i<N;i++){
        cin>>diameter[i];
    }
    // sort the array
    // go through the array counting non duplicate values
    sort(diameter, diameter + N);
    
    // at least one 
    int count = 1;
    for (int i=1;i<N;i++){
        if(diameter[i] != diameter[i-1]){
            count++;
        }
    }
    cout << count;

    return 0;
}
