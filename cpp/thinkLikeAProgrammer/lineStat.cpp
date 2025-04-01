#include<iostream>
#include<string>
#include<sstream>
using namespace std;

bool compareWordLen(string a, string b){
    return a.length() < b.length();

}

int main() {
    string line, word, maxWord = "";
    vector<string> words;
    int count = 0;

    cout << "Enter a line of text: " << endl;
    getline(cin, line);
    stringstream ss(line);
    while (ss>>word){
        words.push_back(word);
        maxWord = max(maxWord, word, compareWordLen);
        count++;

    }
    cout << "Count is: " << count<< endl;
    cout << "Max word is: " << maxWord<< endl;


    return 0;
}
