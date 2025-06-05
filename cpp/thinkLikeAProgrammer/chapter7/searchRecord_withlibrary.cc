#include <iostream>
#include <unordered_map>
using namespace std;

struct studentRecord{
    int grade;
    int studentNum;
    studentRecord(gr, id) : grade(gr), studentNum(id){}
};


void insert(studentRecord * sr, unordered_map<int, studentRecord*> * hash){
    int id = sr->studentNum;
    hash->insert({id, sr});
    return;
}

studentRecord * get(int id, unordered_map<int, studentRecord*> *hash){
    return hash->at(id);
}

void solve(){
    unordered_map<int, studentRecord*> hash; 

}

int main(){
    solve();
    return 0;
}
