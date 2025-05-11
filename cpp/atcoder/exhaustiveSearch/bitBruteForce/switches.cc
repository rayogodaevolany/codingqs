#include <iostream>
#include <vector>
using namespace std;

void answer(){
    int N, M; cin >>N>>M;
    vector<vector<int>>vec(M);

    // loop bulbs amount times
    for(int i=0;i<M;i++){
        int k; cin >>k;
        // resize every int vector to size k
        vec[i].resize(k);
        for(int j=0;j<N;j++){
            // get switch name
            cin>>vec[i][j];
            // convert from 1-index to zero index
            --vec[i][j];
        }
    }

    // parity vector
    vector<int> p(M);
    for(int i=0;i<M;i++)cin >> p[i];
    
    int ans = 0;
    // bit shift by N
    for(int i = 0; i < (1 << N); i++){
    // every subset of N in binary
        bool ok = true;
        for(int j = 0; j < M; j++){
            // every bulb
            int c = 0;
            for(int id: vec[j]){
                //every switch in each bulb
                if((i >> id) & 1){
                    // check if it turns on
                    //check if i is on at index id
                    c++;
                }
            }
            // does the parity align with what it should be?
            c %= 2;
            if(c != p[j]){
                // if any of them is false then the flag is false
                ok = false;
            }
        }
        if(ok){
            ans++;
        }
    }
    cout << ans << endl;
}

int main() {
    int switchesAmount, bulbsAmount, count = 0;

    cin >> switchesAmount >> bulbsAmount;

    vector<vector<int>> bulbs;
    // for amount of bulbs
    for(int i=0;i<bulbsAmount;i++){
        // get amount of connected switches 
        int connected;
        cin >> connected;
        vector<int> switches(switchesAmount, 0);
        // loop to get connected switches
        for(int j=0;j<connected;j++){
            int s;
            cin >> s;
            switches[s-1] = 1;
        }   

        bulbs.push_back(switches);
    }

    vector<int> parity;
    for (int i=0;i<bulbsAmount;i++){
        int p;
        cin >> p;
        parity.push_back(p);
    }

    // all subsets of switchesAmount
    for (int bit=0;bit<(1<<switchesAmount);bit++){
        // in one subset
        vector<int> bulbsParity(bulbsAmount, 0);
        
        for(int i=0;i<switchesAmount;i++){
            if(bit & (1<<i)){
                // make a vector that shows the parity of each?
                // loop through bulbs and check if the bulb has a switch for i
                for (int j=0;j<bulbsAmount;j++){
                    if (bulbs[j][i] == 1){
                        // bulb is connected to switch i
                        // increment parity number of each bulb
                        bulbsParity[j] += 1;
                    }
                }

            }
        }

        // loop through all the parities and see if everything is on
        bool flag = true;
        for(int i=0;i<bulbsAmount;i++){
            if(parity[i] != bulbsParity[i]%2){
                flag = false;
            } 
        }
        if (flag) count++;
    }

    cout << count << endl;

    return 0;
}
