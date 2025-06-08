#include <iostream>
#include <unordered_map>
using namespace std;

struct studentRecord{
    int grade;
    int studentNum;
    studentRecord(int gr, int id) : grade(gr), studentNum(id){}
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
    studentRecord * n1 = new studentRecord(87, 1);
    studentRecord * n2 = new studentRecord(7, 2);
    studentRecord * n3 = new studentRecord(100, 3);

    insert(n1, &hash);
    insert(n2, &hash);
    insert(n3, &hash);

    cout << get(3, &hash)->grade << endl;

}

int main(){
    solve();
    return 0;
}
