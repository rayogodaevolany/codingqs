#include<iostream>
#include<vector>
using namespace std;

// cipher 
char converter(char input){
    // hardcode const array of cipher code
    int cipher[26] = {'B','X','Y','Z','N','M','S','T','V','U','E','D','A','C','F','I','H','L','O','G','J','K','P','Q','R','W'};
    int index;
    // if input is lowercase make adjustments
    if (input - 'a'<=25){
        index = input - 'a';
    } else {
        index = input - 'A';
    }

    // output the corresponding letter according to index of alphabet
    return cipher[index];
}

// a routine that decodes the input
char deconverter(char input){
    // hardcoded cipher array
    int cipher[26] = {'B','X','Y','Z','N','M','S','T','V','U','E','D','A','C','F','I','H','L','O','G','J','K','P','Q','R','W'};
    int index = -1;

    // find the index of input letter 
    for (int i = 0; i < 26; i++){
        if(input != cipher[i]){
            continue;
        }
        index = i;
        break;
    }
    // convert index to alphabet
    char output;
    output = index + 'A';

    // output the corresponding letter according to index of alphabet
    return output;
}
int main(){
    char input;
    char output;
    vector<char> decoded;

    // read plaintext input
    input = cin.get();
    while (input != '\n'){
     
    // if letter is space then print space and continue
        if (input == ' ') {
            decoded.push_back(' ');
            cout << ' ';
            input = cin.get();
            continue;
        }
    // call cipherConverter for each letter
        output = converter(input);
    // decode
        decoded.push_back(deconverter(output));
    // output ciphertext
        cout << output;
    // get next letter
        input = cin.get();
    }
    
    cout << '\n';
    for (int i = 0; i<decoded.size(); i++){
        cout << decoded[i];
    }

    return 0;

}
