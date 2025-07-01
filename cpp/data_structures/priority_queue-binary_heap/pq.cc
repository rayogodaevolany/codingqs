#include "pq.h"
using namespace std;
pq::pq(){
}
void pq::insert(int val){
    arr.push_back(val);
    heapifyUp();
    return;
}

void pq::pop(){
    if (arr.empty()){
        return;
    }
    int last = arr[arr.size() - 1];
    arr.pop_back();
    arr[0] = last;

    heapifyDown();
    return;
}

int pq::peek(){
    if(this->arr.empty()){
        throw "empty!";
    }
    return arr[0];
}

// THE LOGIC IN BOTH UP AND DOWN ARE WRONG HERE
void pq::heapifyUp(){
    bool bigger = true;
    int last = arr.size() - 1;
    // while index is valid
    while(last > 0 || bigger){
        int cur = arr[last];
        int parent = arr[(last - 1)/2];
        bigger = cur > parent;

        //swap
        int tmp = cur;
        arr[last] = parent;
        arr[(last - 1)/2] = tmp;
        // make the last the current's parent
        last = (last - 1)/2;
    }

}
void pq::heapifyDown(){
    _hdHelper(0);
}

void pq::_hdHelper(int val){
    int left = (2*val) + 1;
    int right = (2*val) + 2;
    int lastIndex = arr.size() - 1;

    //basecase leaf nodes
    if (left > lastIndex && right > lastIndex){
        return;
    }
    // do work and recurse
    if(left > lastIndex && arr[val] > arr[left]){
        //swap
        int tmpl = arr[val];
        arr[val] = arr[left];
        arr[left] = tmpl;
        return _hdHelper(left);
    } else if (right > lastIndex && arr[val] > arr[right]){
        //swap
        int tmpr = arr[val];
        arr[val] = arr[right];
        arr[right] = tmpr;
        return _hdHelper(right);
    }
}



