#include<iostream>
#include<vector>

using namespace std;

int main() {
    // count the amount of times every number in the given array can be divided by two
    // add all of the number together and if it is odd stop

    int num;
    // get number of elements
    cin >> num;
    vector<int> elements(num);
    if(num == 0){ return 0;}

    // get elements
    for (int i = 0; i < num; i++){
        cin >> elements[i];
    }

    bool isEven = 1;
    // count runs at least once
    int count = -1;
    // while the elements of the array are even
    while (isEven){
        
        // loop through the array and add them all up
        for (int i = 0; i < num; i++){
            // check if it is even
            if (elements[i] % 2 > 0){
                isEven = 0;
                break;
            }
            // divide by two
            elements[i] /= 2;
        }
        count++;
    }
    // display calculated result
    cout << count;

    /* for (int i = 0; i < num; i++) cout << elements[i] << " "; */
    
    return 0;
}
