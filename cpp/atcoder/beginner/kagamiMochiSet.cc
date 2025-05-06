#include<iostream>
#include<set>
using namespace std;

int main() {
    int N;
    cin >> N;
    int diameter [110];
    for(int i=0;i<N;i++){
        cin>>diameter[i];
    }
    set<int> values;
    for(int i=0;i<N;i++){
        values.insert(diameter[i]);
    }

    cout<< values.size();

    return 0;
}
