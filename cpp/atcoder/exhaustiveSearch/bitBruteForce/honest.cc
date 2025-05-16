#include <iostream>
#include <vector>
using namespace std;

//max subset where people agree
int main(){
    int people; cin >> people;
    vector<vector<int[2]>> verdicts(people);

    for (int i = 0; i < people; i++){
        // for all people
        int testimonies; cin >> testimonies;
        for (int j = 0; j < testimonies; j++){
            // for all testimonies
           int person; cin >> person;
            int verdict; cin >> verdict;
            verdicts[j][i][0] = person;
       }
    }
    return 0;
}
