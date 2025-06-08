#include <string>
#include <unordered_map>
#include <iostream>
using namespace std;
// find the right design pattern for adding multiple 
// pieces of data 
// term, year enrol, audit bool
// decorator pattern

// component interface
// recordInterface
class recordInterface{
    public:
        virtual int grade() = 0;
        virtual int id() = 0;
        virtual ~recordInterface();
        
};

recordInterface::~recordInterface() = default;

// concrete component
// studentRecord
class studentRecord: public recordInterface{
    private:
        int _gr;
        int _i;
    public:
        studentRecord(){
            _gr = 0;
            _i = 0;
        }
        studentRecord(int g, int i){
            _gr = g;
            _i = i;
        }
        int grade() override {
            return _gr;
        }
        int id() override {
            return _i;
        }
};

// baseDecorator
class baseDecorator: public recordInterface{
    protected:
        recordInterface *_wrappee;
    public:
        baseDecorator(recordInterface * wrappee): _wrappee(wrappee){
            if (!_wrappee){
                throw invalid_argument("cannot decorate null record");
            }
       }

        int grade () override {
            return _wrappee->grade();
        }

        int id() override{
            return _wrappee->id();
        }
        ~baseDecorator() override{
            delete _wrappee;
        }
};


// term, year enrol, audit bool
// concreteDecorator
class termDecorator: public baseDecorator{
    private:
        string _t;
    public:
        termDecorator(recordInterface * wrappee, string t):
            baseDecorator(wrappee), _t(t){}
        string term(){
            return _t;
        }
};

class enrolDecorator: public baseDecorator{
    private:
        int _year;
    public:
        enrolDecorator(recordInterface * wrappee, int year):
            baseDecorator(wrappee), _year(year){}
        int enrollyear(){
            return _year;
        }
};

class auditDecorator: public baseDecorator{
    private:
        bool _audit;
    public:
        auditDecorator(recordInterface * wrappee, bool audit):
            baseDecorator(wrappee), _audit(audit){}
        bool audit(){
            return _audit;
        }
};

void insert(recordInterface * sr, unordered_map<int, recordInterface*> * hash){
    int id = sr->id();
    hash->insert({id, sr});
    return;
}

recordInterface * get(int id, unordered_map<int, recordInterface*> *hash){
    return hash->at(id);
}

void solve(){
    unordered_map<int, recordInterface*> hash; 
    studentRecord * n1 = new studentRecord(87, 1);
    studentRecord * n2 = new studentRecord(7, 2);
    studentRecord * n3 = new studentRecord(100, 3);

    insert(n1, &hash);
    insert(n2, &hash);
    insert(n3, &hash);

    recordInterface * a1 = new auditDecorator(n1, true);
    hash[1] = a1;

    recordInterface * retrieved= get(1, &hash);
    cout << (static_cast<auditDecorator *> (retrieved))->audit() << endl;


}

int main(){
    solve();
    return 0;
}
