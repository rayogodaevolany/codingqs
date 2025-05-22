#include <iostream>
#include <climits>
using namespace std;

// what are the properties of a binary search tree
// that the any node in the left subtree are less than the root, 
// and the root is less than any node in the right subtree.


class bst {
    public:
    private:
        struct Node{
            int data;
            Node * left;
            Node * right;
        };
        typedef Node * treePtr;
        treePtr _root;
        bool checkBST(treePtr root, long long min, long long max);
        void insert(treePtr& root, Node * newNode);
};


// If it is the left subtree, it needs to be less than the root node
// check if it has bst properties
bool bst::checkBST(treePtr root, long long min, long long max){
    // basecase
    if (root == nullptr) return true;
    // get rest of the data
    bool leftBool = checkBST(root->left, min, root->data);
    bool rightBool = checkBST(root->right, root->data, max);

    // check the current for bst properties

    return  (min < root->data && root->data < max)
        && leftBool && rightBool;

}


void bst::insert(treePtr& root, Node * newNode){
    // basecase nullptr
    if (root == nullptr) {
        root = newNode;
        return;
    }
    // if bigger than root go right else left
    if (newNode->data > root->data){
        insert(root->right, newNode);
    } else if (newNode->data < root->data){
        insert(root->left, newNode);
    }

}

int main(){
    return 0;
}
