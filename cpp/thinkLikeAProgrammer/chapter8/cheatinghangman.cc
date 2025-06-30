#include <iostream>
using std::cin;
using std::cout;
using std::ios;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <list>
using std::list;
using std::iterator;
#include <cstring>

list<string> readWordFile(char * filename){
    list<string> wordList;
    ifstream wordFile(filename, ios::in);
    if (!wordFile) {
        cout << "File open failed. \n";
        return wordList;
    }
    char currentWord[30];
    while (wordFile >> currentWord){
        // avoid apostrophe words
        if (strchr(currentWord, '\'') == 0){
            string temp (currentWord);
            wordList.push_back(temp);
        }
    }
    return wordList;
}


void displayList(const list<string> & wordList) {
    list<string>::const_iterator iter;
    while (iter != wordList.end()) {
        cout << iter->c_str() << "\n";
        iter++;
    }
}

int countWordsWithoutLetter(const list<string> & wordList, char letter) {
    list<string>::const_iterator iter;
    int count = 0;
    iter = wordList.begin();
    while(iter != wordList.end()) {
        if (iter->find(letter) == string::npos){
            count++;
        }
        iter++;
    }
    return count;
}

void removeWordsOfWrongLength(list<string> & wordList,
        int acceptableLength)
{
    list<string>::iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->length() != acceptableLength){
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

bool numberInPattern(const list<int> & pattern, int number) {
    list<int>::const_iterator iter;
    iter = pattern.begin();
    while (iter != pattern.end()){
        if (*iter == number) {
            return true;
        }
        iter++;
    }
    return false;
}

bool matchesPattern(string word, char letter, list<int> pattern) {
    for (int i = 0; i < word.length(); i++){
        if (word[i] == letter){
            if(!numberInPattern(pattern, i)){
                return false;
            } else {
                if (numberInPattern(pattern, i)){
                    return false;
                }
            }
        }
    }
    return true;
}

void removeWordsWithoutLetter(list<string> & wordList,
        char requiredLetter) {
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (iter->find(requiredLetter) == string::npos) {
            iter = wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void removeWordsWithLetter(list<string> & wordList, char forbiddenLetter){
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()){
        if (iter->find(forbiddenLetter) != string::npos){
            iter= wordList.erase(iter);
        } else {
            iter++;
        }
    }
}

void mostFreqPatternByLetter(list<string> wordList, char letter,
        list<int> & maxPattern,
        int & maxPatternCount) {
    removeWordsWithoutLetter(wordList, letter);
    list<string>::iterator iter;
    maxPatternCount = 0;
    while (wordList.size() > 0){
        iter = wordList.begin();
        list<int> currentPattern;
        for(int i = 0; i < iter->length(); i++){
            //indexing a string
            if((*iter)[i] == letter) {
                currentPattern.push_back(i);
            }
        }
        int currentPatternCount = 1;
        iter = wordList.erase(iter);
        //loop through wordlist again this time 
        //counting how many match and removing the matches
        while (iter != wordList.end()){
            if (matchesPattern(*iter, letter,currentPattern)){
                currentPatternCount++;
                iter = wordList.erase(iter);
            } else {
                iter++;
            }
        }
        if (currentPatternCount > maxPatternCount) {
            maxPatternCount = currentPatternCount;
            maxPattern = currentPattern;
        }
        currentPattern.clear();
    }
}

void displayGuessedLetters(bool letters[26]){
    cout << "Letters guessed: ";
    for (int i = 0; i < 26; i++){
        if (letters[i]) cout << (char)('a' + i) << " ";
    }
    cout << "\n";
}

list<string> reduceByPattern(const list<string> &wordList, char letter, list<int> pattern) {
    list<string> newList;
    list<string>::const_iterator iter;
    iter = wordList.begin();
    while (iter != wordList.end()) {
        if (matchesPattern(*iter, letter, pattern)){
            newList.push_back(*iter);
        }
        iter++;
    }
    return newList;
}


int main (){
    // set up the configuration
    list<string>readWordFile(const string& filename);
    list<string> wordList = readWordFile("word_alpha.txt");
    const int wordLength = 8;
    const int maxMisses = 9;
    int misses = 0;
    int discoveredLetterCount = 0;
    removeWordsOfWrongLength(wordList, wordLength);
    char revealedWord[wordLength + 1] = "********";
    bool guessedLetters[26];
    for (int i = 0; i < 26; i++) guessedLetters[i] = false;
    char nextLetter;
    cout << "Word so far: " << revealedWord << "\n";
    // set up the main game loop
    while (discoveredLetterCount < wordLength && misses < maxMisses) {
        cout << "Letter to guess: ";
        cin >> nextLetter;
        guessedLetters[nextLetter - 'a'] = true;
        int missingCount = countWordsWithoutLetter(wordList, nextLetter);
        list<int> nextPattern;
        int nextPatternCount;
        mostFreqPatternByLetter(wordList, nextLetter, nextPattern, nextPatternCount);
        if (missingCount > nextPatternCount) {
            removeWordsWithLetter(wordList, nextLetter);
            misses++;
        } else {
            list<int>::iterator iter = nextPattern.begin();
            while(iter != nextPattern.end()){
                discoveredLetterCount++;
                revealedWord[*iter] = nextLetter;
                iter++;
            }
            wordList = reduceByPattern(wordList, nextLetter, nextPattern);
        }
        cout << "Word so far: " << revealedWord << "\n";
        displayGuessedLetters(guessedLetters);
    }

    if (misses == maxMisses){
        cout << "Sorry. You lost. The word I was thinking of was '";
        cout << (wordList.cbegin())->c_str() << "'.\n";
    } else {
        cout << "Great job. You win. Word was '" << revealedWord << "'.\n";
    }
    return 0;
}
