#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class studentRecord {
    public: 
        studentRecord();
        studentRecord(string newGrade, string newID) {
            _hash.insert({"grade" , newGrade});
            _hash.insert({"id" , newID});
        }
        void addExtraField(string key, string value){
            _hash.insert({key, value});
        }
        string get(string id){
            return _hash[id];
        }
        
    private:
        unordered_map<string, string> _hash;
};

void solve(){
    studentRecord sr ("25", "1");
    cout << sr.get("grade") << endl;

}

int main(){
    solve();
    return 0;
}
