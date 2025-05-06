#include<iostream>
#include<string>
using namespace std;

int main(){
    // add up all the uppercase letters
    string str, res;
    // get string
    cin >> str;
    
    // loop through every value and add the uppercase
    for (int i = 0; i<int(str.length());i++){
        if(str[i] >= 'A' && str[i] <= 'Z') {
            res.push_back(str[i]);
        }
    }
    // output value
    for(int i = 0; i<int(res.length()); i++){
        cout <<res[i];
    }

}
