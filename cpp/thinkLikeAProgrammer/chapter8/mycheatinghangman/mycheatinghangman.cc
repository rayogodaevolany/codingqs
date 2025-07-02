#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <tuple>
using namespace std;

// The word will be represented using a string.

// get words
// signature: filename->vector<string>
// purpose: get the words from the word file.
// given: "wordlist.txt", expect {"a", "apple", ...}
// function header:
vector<string> getWords(const char* filename){
    // process filename
    vector<string> words;
    ifstream wordFile(filename);
    if (!wordFile.is_open()){
        cout << "File open failed. \n";
        return words;
    }
    char currentWord[30];
    while (wordFile >> currentWord){
        // this check might not be necessary
        if (strchr(currentWord, '\'') == 0){
            string temp (currentWord);
            words.push_back(temp);
        }
    }
    return words;
}


// process
// signature: vector<string> -> vector<unordered_map<char, vector<int>>>
// purpose: create hashmaps to access the pattern of each word
// examples: given {"apple", "tea"}, expect 
                    // {{"a": {0}, "p": {1,2}, "l" : {3}, "e": {4}},
                    // {"t": {0}, "e":{1}, "a": {2}}}
// function header:
vector<unordered_map<char, vector<int>>> makeHashmaps(vector<string> words){
    vector<unordered_map<char, vector<int>>> x ;
    return x;
}


// whittle to length and pattern



// go through patterns


// display list


int main(){
    return 0;
}
