#include<iostream>
using namespace std;

int numberReturn (){
    int number = 0;
    char digitChar;

    cout << "enter any number: ";

    do {
        digitChar = cin.get();
        while ((digitChar != 10) && (digitChar != ',')){
            number =  number * 10 + (digitChar - '0');
            digitChar = cin.get();
        }
        cout << "Number entered: " << number << "\n";
        number = 0;
    } while (digitChar != 10);

    return 0;
}

int alphaLower() {
    cout << "Enter a number 1-26: ";
    int number;
    cin >> number;
    char outputCharacter;
    outputCharacter = number + ('a' - 1);
    cout << "Equivalent symbol: " << outputCharacter << "\n";   
    return 0;
}

int alphaCapital() {
    cout << "Enter a number 1-26: ";
    int number;
    cin >> number;
    char outputCharacter;
    outputCharacter = number + ('A' - 1);
    cout << "Equivalent symbol: " << outputCharacter << "\n";   
    return 0;
}

int symbolConverter() {
    cout << "Enter a number 1-8: ";
    int number;
    cin >> number;
    char outputCharacter;
    switch (number) {
        case 1: outputCharacter = '!'; break;
        case 2: outputCharacter = '?'; break;
        case 3: outputCharacter = ','; break;
        case 4: outputCharacter = '.'; break;
        case 5: outputCharacter = ' '; break;
        case 6: outputCharacter = ';'; break;
        case 7: outputCharacter = '"'; break;
        case 8: outputCharacter = '\''; break;
    }
    return 0;
}

int main() {
   enum modeType {UPPERCASE, LOWERCASE, PUNCTUATION};
   int number;
   modeType mode = UPPERCASE;
   cout << "Enter some numbers ending with -1: ";
   do {
       cin >> number;
       cout << "Num is: " << number;
       switch(mode) {
           case UPPERCASE:
               number = number % 27;
               cout << ". Modulo 27: " << number << ". ";
               if( number == 0) {
                   cout << "Switching to lower. ";
                   mode = LOWERCASE;
               }
               break;

           case LOWERCASE:
               number = number % 27;
               cout << ". Modulo 27: " << number << ". ";
               if( number == 0) {
                   cout << "Switching to punct. ";
                   mode = PUNCTUATION;
               }
               break;

           case PUNCTUATION:
               number = number % 9;
               cout << ". Modulo 9: " << number << ". ";
               if( number == 0) {
                   cout << "Switching to upper. ";
                   mode = UPPERCASE;
               }
               break;
       }
       cout << "\n";
   } while(number != -1);

}
