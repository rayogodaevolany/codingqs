#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};
typedef  Node * listPtr;

// false is even, true is odd
int targetNum(listPtr head, int target){
    if (head == nullptr) return 0;
    int allOthers = targetNum(head->next, target);
    if(head->data == target)allOthers++;
    return allOthers;
}

void test(){
    listPtr test;
    Node * n1 = new Node;
    Node * n2 = new Node;
    Node * n3 = new Node;
    Node * n4 = new Node;
    Node * n5 = new Node;

    n1->data = 11;
    n2->data = 111;
    n3->data = 0;
    n4->data = 0;
    n5->data = 1111;

    test = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    
    n1 = n2 = n3 = n4 = n5 = nullptr;

    int target = 1;
    cout << targetNum(test, target) << endl;

    // go through the ll and deallocate the data
}

int main(){
    test();
    return 0;
}

