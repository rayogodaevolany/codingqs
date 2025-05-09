#include<iostream>
using namespace std;

int main() {
    int nums, count =0;
    string input;
    // digits can be up to 30000
    cin >> nums;
    cin.ignore();
    getline(cin, input);

    // 999 is the limit of what is possible
    // loop from zero to 999 and see if it can be made with the values in the nums
    for(int i=0;i<1000;i++){
        // get the nums of i
        int digits[3] = {i/100, (i/10)%10, i%10};
        // from index 0-2
        int index = 0;
        for(int m=0;m<nums;m++){
            if(input[m] == '0' + digits[index] ){
                    index++;
                    }
            if (index>2){
                break;
            }
        }
        if (index>2){
            count++;
        }
    }
    cout << count;

    return 0;
}

