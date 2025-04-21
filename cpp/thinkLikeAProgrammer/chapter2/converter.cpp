#include<iostream>
#include<cmath>
#include<bitset>
#include<vector>
using namespace std;


bitset<16> setBit(int power, bitset<16> bit){
    unsigned int bit_position = power;
    bitset<16> mask = 1 << bit_position;
    bit = bit ^ mask;
    return bitset<16>(bit);
}

bitset<16> convertToBit(int number) {
    int powerOfTwo = 1;
    int power = 0;
    bitset<16> bit;
    
    while (number > 0) {
        while (number >= powerOfTwo){
            powerOfTwo = pow(2, power);
            power++;
        }
        power -= 2;
        // cout << power << endl;
        number = number - pow(2, power);
        bit = setBit(power, bit);
        power = 1;
        powerOfTwo = 1;
    }

    return bit;
}

char hexDigit(int num) {
    vector<char> hexDigits = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
    
    return hexDigits[num];
}

string convertToHex(int number){
    int power = 0;
    int powerNum = 1;
    string output = "";
    
    while (number > 0) {
        while (number > powerNum && ((number - powerNum) < 16 )){
            power++;
            powerNum = pow(16, power);

        }
        cout << powerNum << endl;
        number = number - powerNum;
        // output = (power, output);
        power = 0;
        powerNum = 1;
    }

    return output;
    
    return "F";
}
int main() {
    int choice;
    int number;
    // enum selectType {BINARY, DECIMAL, HEXADECIMAL};
    // selectType selection = BINARY;

    // cout << "Choose output between 1, 2, 3 (bit, decimal, or hex): ";
    // cin >>  choice;
    cout << "Enter a decimal number: ";
    cin >> number;
    convertToHex(number);

    // switch (choice) {
    //     case 1:
    //         selection = BINARY;
    //         cout << convertToBit(number);
    //         break;
    //     case 2: 
    //         selection = DECIMAL;
    //         cout << number;
    //         break;
    //     case 3: 
    //         selection = HEXADECIMAL;
    //         cout << hex << number;
    //         break;
    // }

    return 0;
}
