#include<iostream>
#include<cmath>
using namespace std;

int processNum(int number) {
    int powerOfTwo = 0;
    int power = 0;
    int remainder;
    
    while (number > powerOfTwo){
        powerOfTwo = pow(2, power);
        power++;
    }
    remainder = number - powerOfTwo;

    return 0;

}
int main() {
    int number;
    cout << "Enter a decimal number: ";
    cin >> number;

    return 0;
}
