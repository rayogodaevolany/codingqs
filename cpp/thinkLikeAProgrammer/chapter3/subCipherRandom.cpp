#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

// routine that generates a random order array of the uppercase alphabet 
// input nothing
// output uppercase alphabet chars in a vector
vector<char> randomCipher(){
    vector<int> alphabet;
    vector<char> randomCipher;
    // create a vector of the alphabet in indexes
     for(int i=0;i<26;i++) alphabet.push_back(i);

    // iterate  26 times 
    for(int i=0;i<26;i++){
        // get a random number using a random number generator
        // while loop to make sure random number is not the same as the index
            int random = i;
            while (random == i){
                // get random number based off of size 
                // of whats left in the alphabet array
                random = rand() % alphabet.size();
            }
        // select index and push letter to random cipher array
            char letter = alphabet[random] + 'A';
            randomCipher.push_back(letter);
        // remove indexed value from array
            auto ne = remove(alphabet.begin(), alphabet.end(), alphabet[random]);
            alphabet.erase(ne, alphabet.end());
    }

    // return randomly generated cipher
    return randomCipher;
}

// cipher that 
char converter(char input, vector<char>& cipher){
    int index;
    // if input is lowercase make adjustments
    if ( 'a'<= input && input <= 'z'){
        index = input - 'a';
    } else if ('A' <= input && input <= 'Z'){
        index = input - 'A';
    } else {
        return input;
    }

    // output the corresponding letter according to index of alphabet
    return cipher[index];
}

// a routine that decodes the input
char deconverter(char input, vector<char>& cipher){
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
    // make rand get different values per run
    srand(time(0));

    char input;
    char output;
    vector<char> decoded;
    // test randomcipher
    vector<char> rcipher;
    rcipher = randomCipher();

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
        output = converter(input, rcipher);
    // decode
        decoded.push_back(deconverter(output, rcipher));
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
