#include <iostream>
#include <string>
using namespace std;


// this routine converts a stringified number into an int number
int convertToInt(string str) {
    // declare number, current variable
    int num = 0, cur;
    // find length of str
    int len = str.length();
    // for length of str from i to end of str convert each to int
    for (int i=0; i<len;i++){
        // find int from string at position i
        cur = str[i] - '0';
        // multiply the original number by ten and add int
        num = (num * 10) + cur;
    }
    // return num
    return num;
}

// This routine converts single decimals into base 16 characters
char singleHex(int digit) {
    // list of characters in base 16
    char list[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    // return character at the right index based on input num
    return list[digit];
}

// this routine converts a stringified decimal number into a stringified hex
string convertToHex(string num){
    // declare results variable
    string res;
    // declare char vector hexNum
    vector<char> hexNum;
    // declare copy of number, quotient
    int copy, quotient;
    // copy num in int form
    copy = convertToInt(num);
    // while copy is not zero
    while (copy != 0) {
    //     get the quotient from dividing number by 16
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
    // declare string str
    // declare string hexstr
    string str, hexstr;
    // ask user for input
    // store input in str
    // call input with converToHex
    // print hexstr
    return 0;
}
