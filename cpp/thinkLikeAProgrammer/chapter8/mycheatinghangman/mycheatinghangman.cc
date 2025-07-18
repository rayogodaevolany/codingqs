#define DOCTEST_CONFIG_IMPLEMENT
#include "doctest.h"
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
TEST_CASE("getWords"){
    vector<string> str = {"apple", "tea"};
    CHECK(getWords("test.txt") == str);
}

//convert to hashmap
//signature: string -> unordered_map<char, vector<int>>
//purpose: make a hashmap version of a string to access its indexes
//example: given "apple", expect 
    // unordered_map<char, vector<int>> hashA = {
    //     {'a', {0}},
    //     {'p', {1,2}},
    //     {'l', {3}},
    //     {'e', {4}}
    // };
// given "tea", expect {"t": {0}, "e":{1}, "a": {2}}}
//function header:
unordered_map<char, vector<int>> makeHash(string str){
    unordered_map<char, vector<int>> hash;
    for (int i = 0; i < static_cast<int>(str.size()); i++){
        hash[str[i]].push_back(i);
    }
    return hash;
}
TEST_CASE("makeHash"){
    string a = "apple";
    unordered_map<char, vector<int>> hashA = {
        {'a', {0}},
        {'p', {1,2}},
        {'l', {3}},
        {'e', {4}}
    };
    CHECK(makeHash(a) == hashA);
}

// convert collection of strings to collection of hashmaps(of the string)
// signature: vector<string> -> vector<unordered_map<char, vector<int>>>
// purpose: create hashmaps to access the pattern of each word
// examples: given {"apple", "tea"}, expect 
// {
//     { 
//         {'a', {0}},
//         {'p', {1,2}},
//         {'l', {3}},
//         {'e', {4}} 
//     }, {
//         { 't', {0}},
//         { 'e', {1}},
//         { 'a', {2}},


//     }
// }
// function header:
vector<unordered_map<char, vector<int>>> processWords(vector<string> words){
    // template
    vector<unordered_map<char,vector<int>>> hashmaps;
    for (int i = 0; i < static_cast<int>(words.size()); i++){
        hashmaps.push_back(makeHash(words[i]));
    }
    return hashmaps;
}
TEST_CASE("processWords"){
    vector<string> vec = {"apple", "tea"};
    vector<unordered_map<char, vector<int>>> ans = {
        { 
            {'a', {0}},
            {'p', {1,2}},
            {'l', {3}},
            {'e', {4}} 
        }, {
            { 't', {0}},
            { 'e', {1}},
            { 'a', {2}},
        }
    };
    CHECK(processWords(vec) == ans);
}


// whittle to length and pattern



// go through patterns


// display list


int main(){
    doctest::Context context;
    int test_result = context.run();
    if (context.shouldExit()) return test_result;
    return 0;
}
