#include<iostream>
#include<string>
using namespace std;

int doubleDigitValue(int digit){
    int doubleDigit = digit * 2;
    int sum;
    if (doubleDigit >= 10) {
        sum = 1 + doubleDigit % 10;
    }
    else sum = doubleDigit;
    return sum;
}

int checksum () {
    char digit;
    int oddChecksum = 0;
    int evenChecksum = 0;
    int position = 1;
    cout << "Enter any even number of  digits: ";
    digit = cin.get();
    while (digit != 10 ) {
        if(position % 2 == 0) {
            evenChecksum += digit - '0';
            oddChecksum += doubleDigitValue(digit - '0');
        } else{
            evenChecksum += doubleDigitValue(digit - '0');
            oddChecksum += digit - '0';
        }
        digit = cin.get();
        position++;
    }
    if ((position - 1) % 2 == 0) {
        cout << "Checksum is " << evenChecksum << ". \n";
        if (evenChecksum % 10 == 0 ) {
            cout << "Checksum is divisible by 10. Valid. \n";
        } else {
            cout << "Checksum failed \n";
        }
    } else {
        cout << "Checksum is " << oddChecksum << ". \n";
        if (oddChecksum % 10 == 0 ) {
            cout << "Checksum is divisible by 10. Valid. \n";
        } else {
            cout << "Checksum failed \n";
        }
    }
    return 0;

}

int main (){
    checksum();
}

