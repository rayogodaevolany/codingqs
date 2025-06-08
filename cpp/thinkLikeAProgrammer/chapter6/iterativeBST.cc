#include <iostream>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;
};
typedef Node * treePtr;


void iterativeInsert(treePtr& root, Node * newNode){
    if (root == nullptr) {
        root = newNode;
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty()){
        Node * currentNode = s.top(); s.pop();
        // if both are null
        if (currentNode->left == nullptr && currentNode->right == nullptr){
            // if less than
            if (currentNode->data < newNode->data){
                currentNode->right = newNode;

            // if greater than
            } else if (currentNode->data > newNode->data){
                currentNode->left = newNode;
            }
            // break out of loop
            break;

        // if only left
        } else if (currentNode->right == nullptr){
            // add to right subtree
            if (newNode->data > currentNode->data){
                currentNode->right = newNode;
            }
            s.push(currentNode->left);

        // if only right
        } else if (currentNode->left == nullptr) {
            // add to left subtree
            if (newNode->data < currentNode->data){
                currentNode->left = newNode;
            }
            s.push(currentNode->right);
        } else {
            // if newNode data is bigger than currentNode data
            if (currentNode->data < newNode->data){
                // go right
                s.push(currentNode->right);
            } else if (currentNode->data > newNode->data){
                // go left
                s.push(currentNode->left);
            }
        }

    }

    return;
}

void standardIterative(treePtr& root, Node * newNode){
    // root is null
    if (root == nullptr){
        root = newNode;
        return;
    }
    // while pointer to root is not null
    Node * trailer = nullptr; 
    Node * pointer = root;
    while (pointer != nullptr){
        // new is smaller than root
        if (newNode->data < pointer->data){
            trailer = pointer;
            pointer = pointer->left;
        // new is bigger than root
        } else if (newNode->data > pointer->data){
            trailer = pointer;
            pointer = pointer->right;
        } else {
            cout << "Duplicate" << endl;
            return;
        }
    }
    //if new is less than root
    if ( newNode->data < trailer->data){
        trailer->left = newNode;
    } else if (newNode->data > trailer->data){
        trailer->right = newNode;
    }
    // go right or left
    // add to root in the correct side
}

void delegateIterative(treePtr& root, Node * newNode){
    if (root == nullptr) {
        root = newNode;
        return;
    }

    // check if new node should be added to right or left
    // is new less than root?
    if (root->left == nullptr && newNode->data < root->data){
        root->left = newNode;
        return;

    // is new greater than root?
    } else if (root->right == nullptr && newNode->data > root->data){
        root->right = newNode;
        return;
    }

    // delegate
    // if new is less than root
    if (newNode->data < root->data){
        standardIterative(root->left, newNode);
        
    // if new is greater than root
    } else if (newNode->data > root->data){
        standardIterative(root->right, newNode);
    }
}


void recursive(treePtr& root, Node * newNode){
    if (root == nullptr) {
        root = newNode;
        return;
    }

    // check if new node should be added to right or left
    // is new less than root?
    if (root->left == nullptr && newNode->data < root->data){
        root->left = newNode;
        return;

    // is new greater than root?
    } else if (root->right == nullptr && newNode->data > root->data){
        root->right = newNode;
        return;
    }

    // delegate
    // if new is less than root
    if (newNode->data < root->data){
        recursive(root->left, newNode);
        
    // if new is greater than root
    } else if (newNode->data > root->data){
        recursive(root->right, newNode);
    }
}
