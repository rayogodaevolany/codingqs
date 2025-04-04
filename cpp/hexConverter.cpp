#include <iostream>
#include <string>
using namespace std;


// this routine converts a stringified number into an int number
int convertToInt(string str) {
    // declare number, current variable, length of string
    int num = 0, cur;
    int len = str.length();
    // for the length of the string
    for (int i=0; i<len;i++){
        // get the int in the string at index i
        cur = str[i] - '0';
        // multiply the original number by ten and add int
        num = (num * 10) + cur;
    }
    return num;
}

// This routine converts single decimals into base 16 characters
char singleHex(int digit) {
    // list of characters in base 16
    char list[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    // return hex converted character
    return list[digit];
}

// this routine converts a stringified decimal number into a stringified hex
string convertToHex(string num){
    string res;
    vector<char> hexNum;
    int copy, quotient;
    // convert inputted string to int form
    copy = convertToInt(num);

    // while the original number is still valid
    while (copy != 0) {
    //     get the quotient 
        quotient = copy/16;
    //     convert quotient into hex character
        quotient = singleHex(quotient);
    //     add quotient to the back of hexNum
        hexNum.push_back(quotient);
    //     make the copy equal to the remainder
        copy = copy%16;
    }
    // loop through hexNum 
    for (int i = 0; i < hexNum.size();i++){
    //     concatenate the chars into a string
        res += hexNum[i];

    }
    // return string hex
    return res;

}

int main() {
    string str, hexstr;
    cout << "Enter a decimal number" << endl;
    cin >> str;

    hexstr = convertToHex(str);
    cout << hexstr;
    return 0;
}
