#include<iostream>
#include<string>
using namespace std;

// routine that recursively breaks down a string to see if it is a palindrome
// takes a string outputs bool
    // basecase is a single or no letters
    // arg passed to recursive call: the string minus the head and tail
    // arg goes closer to basecase because it is shrinking

bool isPal(string str){
    //if single letter or empty string return true
    if (str.length() == 1 || str.length() == 0){
        return true;
    }
    //take head and tail of string
    char head = str[0];
    char tail = str.back();
    //get the middle
    string middle = str.substr(1, str.length() - 2);
    //return the boolean result of whether the head and tail are the same and the result of recursive call with middle
    if (head == tail && isPal(middle)){
        return true;
    }
    return false;
}

int main(){
// write a palindrome to test
    string hi;
    getline(cin, hi);
    cout << isPal(hi);

    return 0;

}
