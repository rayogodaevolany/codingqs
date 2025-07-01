#ifndef MYHASHMAP_H
#define MYHASHMAP_H

#include <cstddef>
#include <string>
using namespace std;
class myhashmap{
    public:
        myhashmap();
        void insert(string key, int value);
        int get(string key);
    private:
        struct collisionNode{
            string key;
            int value;
            collisionNode * next;
            collisionNode(string key, int value): 
                key(key), value(value), next(nullptr) {}
        };
        collisionNode* traverseByKey(int index, string key);
        int hash(string str);
        typedef collisionNode* collisionHead;
        static const int hashArrSize = 100;
        collisionHead  _hashArray[hashArrSize];
};

#endif
