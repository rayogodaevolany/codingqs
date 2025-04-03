#include<iostream>
#include<string>

using namespace std;

string reverseString(string str) {
    if (str == "" || str.length() == 1){
        return str;
    }
    string res;
    res = reverseString(str.substr(1)) + *str.begin();

    return res;
}

int main () {
    string str;
    cout << "Enter a string: ";
    cin >> str;

    cout << reverseString(str);
}
