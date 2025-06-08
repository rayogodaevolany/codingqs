#include "bst.h"
#include <iostream>
using namespace std;

BST::BST(){
    _root = nullptr;
}
 
// BST::studentRecord * BST::lookupHelper(studentHead root, int val){
//     if (root == nullptr){
//         return nullptr;
//     }

//     studentRecord * left = nullptr;
//     studentRecord * right = nullptr;
//     if (root->studentNum > val){
//         left = lookupHelper(root->left, val);
//     } else if (root->studentNum < val){
//         right = lookupHelper(root->right, val);
//     }

//     if (root->studentNum == val){
//         return root;
//     } else {
//         return left !=nullptr? left : right != nullptr? right : nullptr;
//     }

// }

BST::studentRecord * BST::lookupHelper(studentHead root, int val){
    if (root == nullptr){
        return nullptr;
    }

    if (root->studentNum == val){
        return root;
    }

    if (root->studentNum > val){
        return lookupHelper(root->left, val);
    } else {
        return lookupHelper(root->right, val);
    }

}

BST::studentRecord * BST::lookup(int studentNum){
    return lookupHelper(_root, studentNum);
}

BST::studentRecord* BST::insertHelper(studentHead node, studentRecord * newRecord ){
    // base case insert if null
    if (node == nullptr){
        return newRecord;
    }
    if (node->studentNum > newRecord->studentNum){
        node->left = insertHelper(node->left, newRecord);
    } else if (node->studentNum < newRecord->studentNum){
        node->right = insertHelper(node->right, newRecord);
    }
    return node;
}

void BST::insertRecord(studentRecord * record){
    if (_root == nullptr){
        _root = record; 
    } else {
        // traverse tree according to studentNum of new record
        _root = insertHelper(_root, record);
        // insert into bst
    }

}

int BST::interpolation(int id, studentRecord ** arr, size_t size){
    // initialize low high and pos
    int low = 0, high = size - 1, pos;
    bool found = false;
    // loop until the answer is found or doesn't exist
    while ((id >= arr[low]->studentNum && id <= arr[high]->studentNum)){
        // set the checker to half like in binary search first
        pos =  low + ((id - arr[low]->studentNum) / (arr[high]->studentNum - arr[low]->studentNum)) * (high - low);
        // change low and high based on the id
        if (arr[pos]->studentNum > id){
            high = pos -1;
        } else if (arr[pos]->studentNum < id){
            low = pos + 1;
        } else {
            found = true;
            break;
        }

    }
    if (found) return pos;
    else return -1;
}

// studentRecord** studentArray(){
//     int grades[10] = {87,98,82,72,65,7,28,93,99,45};

//     studentRecord ** stuArr = new studentRecord*[10];

//     for (int i = 0; i < 10; i++){
//         studentRecord * tmp = new studentRecord;
//         tmp->grade = grades[i];
//         tmp->studentNum = i + 1;
//         stuArr[i] = tmp;
//     }
//     return stuArr;
// }

// int comp(const void * a, const void * b){
//      studentRecord *stuA = *static_cast< studentRecord* const*>(a);
//      studentRecord *stuB = *static_cast< studentRecord* const *>(b);
//     return stuA->studentNum - stuB->studentNum;
// }


// void solve(){
//     studentRecord ** arr = studentArray();
//     qsort(arr, 10, sizeof(studentRecord *), comp);

//     for (int i = 0; i < 10; i++){
//         cout << arr[i]->studentNum << " ";
//     }
//     cout << endl;
//     cout << interpolation(10, arr, 10) <<endl;

// }

int main(){
    // solve();
    return 0;
}
