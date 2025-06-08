#include "myhashmap.h"
#include <string>
#include <iostream>
using namespace std;

// how are hashmaps implemented?
// Hash the input value to an index to place in an array
//
myhashmap::myhashmap() {
    for (int i = 0; i < hashArrSize; i++){
        _hashArray[i] = nullptr;
    }
}

//java string hash
int myhashmap::hash(string str){
    // loop over string
    int hash = 0;
    for (int i = 0; i < str.size(); i++){
        hash = hash * 31 + static_cast<int>(str[i]);
    }
    return hash % hashArrSize;
}

myhashmap::collisionNode* myhashmap::traverseByKey(int index, string key){
   if (_hashArray[index] == nullptr){
       collisionNode * pointer = nullptr;
       return pointer;
   }
   collisionNode * pointer = _hashArray[index];
   while ( pointer != nullptr && pointer->key != key){
       pointer = pointer->next;
   }
   return pointer;
}

void myhashmap::insert(string key, int value){
    int index = hash(key);
    if (_hashArray[index] == nullptr){
        // make new 
        collisionNode* newNode = new collisionNode(key, value);
        //add to linked list
        _hashArray[index] = newNode;
    } else {
        collisionNode * pointer = traverseByKey(index, key);

        if (pointer != nullptr){
            pointer->value = value;
            return;
        }
        // make new pointer
        collisionNode* newNode = new collisionNode(key, value);
        //add to linked list
        pointer->next = newNode;
    }
    return;
}

int myhashmap::get(string key){
    // use hash to find index
    int index = hash(key);
    collisionNode * pointer = traverseByKey(index, key);

    if(pointer == nullptr){
        // some kind of error value is obviously better
        return 0;
    } else {
        return pointer->value;
    }
}

// deal with collision using a linkedlist

// void testhashmap(){
//     myhashmap h = myhashmap();
//     cout << int('h') <<  ' ' << int('i');
//     cout << h.hash("hi");
// }

int main(){
    // testhashmap();

    return 0;
}
