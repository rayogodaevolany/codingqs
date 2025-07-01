#include <iostream>
#include "pq.h"
using namespace std;

int main(){
    pq mypq;
    mypq.insert(1);
    mypq.insert(9);
    mypq.insert(4);
    mypq.insert(67890);

    cout << mypq.peek()<<endl;
    mypq.pop();
    cout << mypq.peek()<<endl;

}
