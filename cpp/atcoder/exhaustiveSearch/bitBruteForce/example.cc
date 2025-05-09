#include<iostream>
#include<vector>
using namespace std;

vector<int> intToVec(int bit, int N){
    vector<int> S;
    for(int i = 0;i<N;i++){
        // convert binary numbers into index array
        if(bit & (1 << i)){
            S.push_back(i);
        }
    }
    return S;
}

int main(){
    int N,W;
    cin >> N >> W;
    vector<int> a(N);
    for(int i=0;i<N;i++)cin >> a[i];


    bool exist = false;
    for(int bit=0; bit< (1<<N);bit++){
        vector<int> S = intToVec(bit, N);

        int sum = 0;
        for(int i : S) sum += a[i];

        if (sum == W)exist = true;

    }
    if(exist) cout << "Y" << endl;
    else cout <<"N"<<endl;

    return 0;
}

