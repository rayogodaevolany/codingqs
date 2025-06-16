#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//max subset where people agree
int main(){
    int people; cin >> people;

    vector<vector<pair<int, int>>> verdicts(people);

    for (int i = 0; i < people; i++){
        // for all people
        int testimonies; cin >> testimonies;
        for (int j = 0; j < testimonies; j++){
            // for all testimonies
           int person; cin >> person;
            int verdict; cin >> verdict;

            // convert to zero indexing
            verdicts[i].emplace_back(person - 1, verdict);
        }
    }

    int count = 0;

    // all possible subsets of verdicts
    for (int bit = 0; bit< (1<<people); bit++){
<<<<<<< HEAD
        // COULD JUST START AT ONE
        if (bit == (~0)){
            continue;
        }
=======
        // set the flag every time
        bool flag = true;

        // set vector everytime 
        vector<int> honest(people, -1);

        // loop through the bit
>>>>>>> 344ed87 (Some random stuff)
        for(int i = 0; i< people;i++){
            // if the flag is on
            if(bit & (1 << i)){
                // find result of testimonies of this person
                for( auto& ver :verdicts[i]){
                    if (honest[ver.first] == -1){
                        honest[ver.first] = ver.second;
                    } else if( honest[ver.first] != ver.second){
                        flag = false;
                        break;
                    }
                }
            }
            if(!flag) break;
        }
        // sum the honest array and see its count

        // if it isn't contradictory
        if(flag){
            int sum = __builtin_popcount(bit);
            count = max(count, sum);
        }

    }

    cout << count << endl;
    return 0;
}
