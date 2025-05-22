#include <iostream>
#include <climits>
using namespace std;

// what are the properties of a binary search tree
// that the any node in the left subtree are less than the root, 
// and the root is less than any node in the right subtree.


// all of my bst checking code has the same fundamental problem
// The equalities are only upheld at the local level.
// On the global level the inequalities dont hold up.
//     5
//      \
//      6
//    /  
//    3  
//
// This would be checked as a good bst tree when it is not.
//
// How can I make this so that its fine?
// It needs a global variable? like a global max?
// Like the child nodes of 6 needs to be alway bigger than 5 less than 6
//
// Check that all nodes are less than root?
// all nodes are greater than root?
// Recursively repeat?
    

class bst {
    public:
        bool check();
    private:
        struct Node{
            int data;
            Node * left;
            Node * right;
        };
        typedef Node * treePtr;
        treePtr _root;
        bool checkBST(treePtr root, long long min, long long max);
        bool checkBSTImproved(treePtr root);
        bool checkBSTRefactored(treePtr root);
};

bool bst::check(){

}

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


// bool bst::checkBSTRefactored(treePtr root){
//     // basecase
//     if (root == nullptr) return true;
//     if (root->left == nullptr && root->right == nullptr) {
//         return true;
//     }
//     // get rest of the data
//     bool leftBool = checkBSTRefactored(root->left);
//     bool rightBool = checkBSTRefactored(root->right);


//     bool currentLeft = (root->left == nullptr) 
//         || root->left->data < root->data;
//     bool currentRight = (root->right == nullptr)
//         || root->right->data > root->data;

//     if (!currentLeft || !currentRight) return false;
//     else return leftBool && rightBool;
// }

// bool bst::checkBSTImproved(treePtr root){
//     // basecase
//     if (root == nullptr) return true;

//     // check nodes for bst properties
//     bool leftBool = (root->left == nullptr) 
//         || root->left->data < root->data;
//     bool rightBool = (root->right == nullptr)
//         || root->right->data > root->data;

//     if (!leftBool || !rightBool){
//         return false;
//     }

//     // return recursive calls
//     return checkBSTImproved(root->left) && checkBSTImproved(root->right);

// }




int main(){
    return 0;
}
