#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int getLines(string text) {
    ifstream in(text);
    int counter = 0;
    string buf;
    vector<string> words;
    while(in >> buf){
        counter++;
    }
    return counter;
}

int countSpecificWord(string text, string specificWord){
    ifstream in(text);
    int counter = 0;
    string buf;
    vector<string> words;
    while(in >> buf){
        words.push_back(buf);
    }
    for(int i = 0; i < words.size(); i++){
        if (words[i] == specificWord){
            counter++;
        }
    }
    return counter;
}

int main() {
    string text = "shakespeare.txt";
    // int res = getLines(text);
    string specificWord = "is";
    int res = countSpecificWord(text, specificWord);
    cout << res;
    
    return 0;
}

