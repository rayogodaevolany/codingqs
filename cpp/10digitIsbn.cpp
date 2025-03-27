#include<iostream>
using namespace std;


int main() {
    char digit;
    int number, remainder, checkdigit;
    int sum = 0;
    int multiple = 10;
    cout << "Enter 9 digits: ";
    digit = cin.get();
    // 10 is the end of line
    while(digit != 10){
        number = digit - '0';
        sum += multiple  * number;
        multiple -= 1;

        digit = cin.get();
    }
    remainder = sum % 11;
    checkdigit = 11 - remainder;
    cout << checkdigit;
    return 0;

}
