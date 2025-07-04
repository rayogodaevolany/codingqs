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
    string currentWord;
    while (wordFile >> currentWord){
        // this check might not be necessary
        string temp (currentWord);
        words.push_back(temp);
    }
    return words;
}

//convert to hashmap
//signature: string -> unordered_map<char, vector<int>>
//purpose: make a hashmap version of a string to access its indexes
//example: given "apple", expect {"a": {0}, "p": {1,2}, "l" : {3}, "e": {4}}
// given "tea", expect {"t": {0}, "e":{1}, "a": {2}}}
//function header:
unordered_map<char, vector<int>> makeHash(string str){
    unordered_map<char, vector<int>> hash;
    for (int i = 0; i < static_cast<int>(str.size()); i++){
        hash[str[i]].push_back(i);
    }
    return hash;
}

// convert collection of strings to collection of hashmaps(of the string)
// signature: vector<string> -> vector<unordered_map<char, vector<int>>>
// purpose: create hashmaps to access the pattern of each word
// examples: given {"apple", "tea"}, expect 
                    // {{"a": {0}, "p": {1,2}, "l" : {3}, "e": {4}},
                    // {"t": {0}, "e":{1}, "a": {2}}}
// function header:
vector<unordered_map<char, vector<int>>> processWords(vector<string> words){
    // template
    vector<unordered_map<char,vector<int>>> hashmaps;
    for (int i = 0; i < static_cast<int>(words.size()); i++){
        hashmaps.push_back(makeHash(words[i]));
    }
    return hashmaps;
}


// whittle to length and pattern



// go through patterns


// display list

void test(){
    // vector<string> test;
    // test = getWords("words_alpha.txt");
    // for (string str : test){
    //     cout << str.c_str() << endl;
    // }

    // string test = "tea";
    // unordered_map<char, vector<int>> testhash;
    // testhash = makeHash(test);
    // for (auto pair : testhash){
    //     for (int i = 0; i < (int) pair.second.size(); i++){
    //         cout << pair.first << " " << pair.second[i] << endl;
    //     }
    // }
    
    // vector<unordered_map<char, vector<int>>> testprocessedwords;
    // testprocessedwords = processWords(getWords("test.txt"));
    // for (int j = 0; j < (int)testprocessedwords.size(); j++){
    //     for (auto pair : testprocessedwords[j]){
    //         cout << pair.first << " ";
    //         for (int i = 0; i < (int) pair.second.size(); i++){
    //             cout << " " << pair.second[i];
    //         }
    //         cout << endl;
    //     }
    //     cout << endl;
    // }

}

int main(){
    test();
    return 0;
}
