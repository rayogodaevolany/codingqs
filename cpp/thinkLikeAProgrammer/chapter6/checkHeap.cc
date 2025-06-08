#include <iostream>
#include <queue>
using namespace std;

class binaryTree {
    public:
        binaryTree();
        bool checkHeap();
    private:
        struct Node{
            int data;
            Node * left;
            Node * right;
        };
        typedef Node * treePtr;
        treePtr _root;
        int countNodes(treePtr root);
        bool isComplete(treePtr root, int index, int numberOfNodes);
        bool iterIsComplete(treePtr root);
        bool hasHeapProperties(treePtr root);
        bool isHeap_improved(treePtr root);
};

// need a count of trees
int binaryTree::countNodes(treePtr root){
    if (root == nullptr){
        return 0;
    }
    return countNodes(root->right) + countNodes(root->left) + 1;
}

// need to check completeness
// if right node is filled when the left isn't it is not complete
bool binaryTree::isComplete(treePtr root, int index, int numberOfNodes){
    if (root == nullptr) return true;
    // check if there is a gap in the index
    if (index >= numberOfNodes)return false;

    return isComplete(root->right, 2 * index + 2, numberOfNodes) 
        && isComplete(root->left, 2 * index + 1, numberOfNodes);
}

bool binaryTree::iterIsComplete(treePtr root){
    // use queue and bfs through the binary tree
    // use a flag to see if there were any leaf nodes
    // if the flag is on and a node is found then it is not a binary tree.
    queue <Node *> q;
    q.push(root);
    bool nullNodeSeen = false;

    // loop through entire binary tree
    while (!q.empty()){
        // get the front of queue
        Node * currentNode = q.front(); q.pop();

        if (currentNode->left != nullptr) {
            if (nullNodeSeen) return false;
            q.push(currentNode->left);
        } else {
            nullNodeSeen = true;
        }

        if (currentNode->right != nullptr) {
            if (nullNodeSeen) return false;
            q.push(currentNode->right);
        } else {
            nullNodeSeen = true;
        }
    }
    return true;

    
}

// check for heap properties: whether the root is greater child nodes
bool binaryTree::hasHeapProperties(treePtr root){
    // base case
    if (root == nullptr) return true;
    // rest of the info
    bool restBool = true;
    if (root->left != nullptr && root->right != nullptr){
        restBool = hasHeapProperties(root->left) && hasHeapProperties(root->right);
    } else if (root->left != nullptr){
        restBool = hasHeapProperties(root->left);
    } else if (root->right != nullptr) {
        restBool = hasHeapProperties(root->right);
    }
    // check whether the current node has heap properties
    bool currentBool = true;
    if (root->left != nullptr && root->left->data >= root->data){
        currentBool = false;
    } else if (root->right != nullptr && root->right->data >= root->data){
        currentBool = false;
    }
    return currentBool && restBool;

}

bool binaryTree::isHeap_improved(treePtr root){
    if (root == nullptr){
        return true;
    }
    
    // check current node heap properties
    bool leftBool = (root->left == nullptr) || (root->data >= root->left->data);
    bool rightBool = (root->right == nullptr) || (root->data >= root->right->data);

    if (!leftBool || !rightBool){
        return false;
    }
    // recursive call for subtrees
    return isHeap_improved(root->left) && isHeap_improved(root->right);
}

// need to check heap properties

// should be a complete tree
// should have heap properties: every node should be greater than 
// or equal to its child node
bool binaryTree::checkHeap(){
    int count = countNodes(_root);
    if (isComplete( _root, 0, count) && hasHeapProperties(_root)){
        return true;
    }
    return false;
}

void test(){
}
int main(){
    test();
    return 0;
}
