#include <string>
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
        virtual int grade();
        virtual int id();
        virtual void display();
        virtual ~recordInterface() = default;
};

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
        int grade() {
            return _gr;
        }
        int id(){
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

        int grade(){
            return _wrappee->grade();
        }

        int id(){
            return _wrappee->id();
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

void solve(){

}

int main(){
    solve();
    return 0;
}
