#ifndef PQ_H 
#define PQ_H 
#include <cstddef>
#include <vector>
using namespace std;

// heapify up and heapify down
// has the min heap property
// is a complete tree
class pq{
    public:
        pq();
        void insert(int val);
        void pop();
        int peek();
    private:
        vector<int> arr;
        void heapifyUp();
        void heapifyDown();
        void _hdHelper(int val);
         
};

#endif

