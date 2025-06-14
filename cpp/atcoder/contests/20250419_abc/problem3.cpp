#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;

// find out how many dishes can be eaten on what day
int main(){
    // get types of ingredients,
    int numingre;
    cin >> numingre;
    // get num of dishes
    int numdishes;
    cin >> numdishes;

    int numIngPerDish;
    vector<vector<int>> List;
    vector<int> ingList;

    // for the num of dishes
    for (int i=0;i<numdishes;i++){
       // get the number of ingredients 
       cin >> numIngPerDish;
       for (int j =0; j< numIngPerDish;j++){
           // create ingredients list
           int x;
           cin >> x;
           ingList.push_back(x);
       }
       List.push_back(ingList);
       
    }

    int overcome, count = 0;
    
    // loop over overcome ingredients 
    for(int i=0; i<numingre;i++){
        // get the overcome ingredient of that day
        cin >> overcome;

        bool in;
        // then check all of the dishes
        for(int j = 0; j<int(List.size());j++){
            in = find(begin(List[i]), end(List[i]), overcome)!=end(List[i]);
            // check the dish is overcome, then increment count
            if (!in){
                count++;
            }
        }
        cout << count<<endl;
        // reset count 
        count = 0;
    }
    return 0;
}
