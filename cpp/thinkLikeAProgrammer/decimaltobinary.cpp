#include<iostream>
#include<cmath>
#include<bitset>
using namespace std;


int testBit(){
    unsigned int bit_position = 2;
    unsigned int bit = 0;
    unsigned int mask = 1 << bit_position;
    bit = bit ^ mask;
    cout << bitset<16>(bit) <<endl;
    
    return 0;
}

bitset<16> setBit(int power, bitset<16> bit){
    unsigned int bit_position = power;
    bitset<16> mask = 1 << bit_position;
    bit = bit ^ mask;
    return bitset<16>(bit);
}

bitset<16> processNum(int number) {
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
int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;
    
    // processNum(number);
    cout << processNum(number);

    return 0;
}
