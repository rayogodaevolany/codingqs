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

bool numberInPatter(const list<int> & pattern, int number) {
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
