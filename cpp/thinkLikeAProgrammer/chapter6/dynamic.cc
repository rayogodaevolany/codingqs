#include <iostream>
using namespace std;

struct listNode{
    int data;
    listNode * next;
};

typedef listNode * listPtr;

struct treeNode{
    int data;
    treeNode * left;
    treeNode * right;
};
typedef treeNode * treePtr;

// how many negative numbers in the linked list
int negNums(listPtr head){
    // minimal val
    if(head == nullptr) return 0;

    int count = negNums(head->next);
    if(head->data < 0) count++;
    return count;
}

int largestNum(treePtr root){
    if(root == nullptr) return 0;
    if(root->left == nullptr && root->right == nullptr) return root->data;
    int leftLargest = largestNum(root->left);
    int rightLargest = largestNum(root->right);
    int max = root->data;
    if(leftLargest > max) max = leftLargest;
    if(rightLargest >max) max = rightLargest;
    return max;
}


void displayInOrder(listPtr head){
    if(head!=nullptr){
        cout << head->data << endl;
        displayInOrder(head->next);
    }
}

void displayInReverse(listPtr head){
    if(head!=nullptr){
        displayInReverse(head->next);
        cout << head->data << endl;
    }
}

void iterInOrder(listPtr head){
    for(listPtr current = head; current != nullptr; current = current->next) {
        cout << current->data << endl;
    }
}

void iterInReverse(listPtr head){
    stack<listPtr> nodes;
    for(listPtr current = head; current !=nullptr; current = current->next){
        nodes.push(current);
    }
    while(!nodes.empty()){
        listPtr current = nodes.top();
        nodes.pop();
        cout << current->data << endl;
    }
}

int main(){
    return 0;
}
