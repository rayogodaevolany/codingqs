#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//max subset where people agree
int main(){
    int people; cin >> people;

    // bit table of who is honest
    vector<int> honest(people, 1);
    vector<vector<pair<int, int>>> verdicts(people);

    for (int i = 0; i < people; i++){
        // for all people
        int testimonies; cin >> testimonies;
        for (int j = 0; j < testimonies; j++){
            // for all testimonies
           int person; cin >> person;
            int verdict; cin >> verdict;

            verdicts[i].emplace_back(person, verdict);
        }
    }

    int count = 0;

    // all possible subsets of verdicts
    // every combination of who to believe in
    for (int bit = 0; bit< (1<<people); bit++){
        // COULD JUST START AT ONE
        if (bit == (~0)){
            continue;
        }
        for(int i = 0; i< people;i++){
            // if the flag is on
            if(bit & (1 << i)){
                // find result of testimonies of this person
                for( auto& ver :verdicts[i]){
                    if (ver.second == 0){
                        //if dishonest
                        // turn off the flag for dis person
                        honest[ver.first] = 0;

                    }
                }
            }
        }
        for(auto& h: honest){
            cout << h << endl;
        }
        cout << " big gap " << endl;
        // sum the honest array and see its count
        int sum = 0;
        for(int i = 0; i < honest.size(); i++){
            sum += honest[i];
            // reset honest array
            honest[i] = 1;
        }
        if (count < sum) count = sum;
    }

    cout << count << endl;
    return 0;
}
