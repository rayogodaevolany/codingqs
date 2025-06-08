#include <iostream>
using namespace std;

class binaryTree{
    public:
        int publicCountLeaves();
        int stackBasedCountLeaves();
        bool isHeap();
    private:
        struct binaryTreeNode{
            int data;
            binaryTreeNode * left;
            binaryTreeNode * right;
        };
        typedef binaryTreeNode * treePtr;
        treePtr _root;
        int privateCountLeaves(treePtr rootPtr);
        bool privateIsHeap(treePtr root);

};

bool binaryTree::isHeap(){
    return privateIsHeap(_root);
}

bool binaryTree::privateIsHeap(treePtr root){
    if (root->left == nullptr && root->right == nullptr){
        return true;
    }
    bool rightBool = privateIsHeap(root->right);
    bool leftBool = privateIsHeap(root->left);

    if (root->right == nullptr && root->left->data < root->data && leftBool){
        return true;
    }
    if (root->left == nullptr)return false;
    if (
            root->right->data < root->data 
            && root->left->data < root->data
            && rightBool
            && leftBool
            ){
        return true;
    }
    else return false;

}

int binaryTree::publicCountLeaves(){
    return privateCountLeaves(_root);
} 

int binaryTree::privateCountLeaves(treePtr rootPtr){
    if(rootPtr == nullptr) return 0;
    if(rootPtr->left == nullptr && rootPtr->right == nullptr)
        return 1;
    int leftLeaves = privateCountLeaves(rootPtr->left);
    int rightLeaves = privateCountLeaves(rootPtr->right);

    return leftLeaves + rightLeaves;
}

int binaryTree::stackBasedCountLeaves(){
    if(_root == nullptr) return 0;
    int leafCount = 0;
    stack<binaryTreeNode *> nodes;
    nodes.push(_root);
    while(!nodes.empty()){
        treePtr currentNode = nodes.top();
        nodes.pop();
        if(currentNode->left == nullptr && currentNode->right == nullptr)
            leafCount++;
        else {
            if (currentNode->right != nullptr) nodes.push(currentNode->right);
            if (currentNode->left != nullptr) nodes.push(currentNode->left);
        }
    }
    return leafCount;
}



int main(){
    return 0;
}
