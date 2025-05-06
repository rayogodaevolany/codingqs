#include<iostream>
#include<string>
#include<vector>
using namespace std;

// routine that concats an array of strings into one
// input: array of strings
// output: string
// basecase: empty array or single string
// args to recursive calls: tail
// tail gets smaller over time
string concat(const vector<string>& strs, size_t index = 0){
    //basecase
    if (index >= strs.size()){
        return "";
    }
    // make the first string the head
    string head = strs[index];
    //  retun the addition of head to result of recursive call to tail
    return head + concat(strs, index+1);
}

int main(){
    // hardcode array of strings
    vector<string> strs = {"hi", "hello", "why"};
    
    // pass strings to concat
    // output concatenated string
    cout << concat(strs);
    
    return 0;
}
