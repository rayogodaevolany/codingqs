#include<iostream>
#include<algorithm>
#include<functional>

using namespace std;

bool comp (int a, int b){
    return b < a;
}

int main(){
    int N;
    cin >> N;

    int arr[110];

    for(int i=0;i<N;i++){
        cin >> arr[i];
    }

    // sort vector
    sort(arr, arr + N, greater<int>());

    int sumA = 0;
    int sumB = 0;
    for(int i=0;i<N;i+=2){
        sumA += arr[i];
        sumB += arr[i+1];
    }
    cout << sumA - sumB;
    return 0;
}
