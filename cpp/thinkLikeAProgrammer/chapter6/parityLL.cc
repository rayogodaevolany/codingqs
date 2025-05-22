#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};
typedef  Node * listPtr;

// false is even, true is odd
bool parity(listPtr head){
    if (head == nullptr) return false;
    bool allOthers = parity(head->next);
    if(head->data == 1)allOthers = !allOthers;
    return allOthers;
}

void test(){
    listPtr test;
    Node * n1 = new Node;
    Node * n2 = new Node;
    Node * n3 = new Node;
    Node * n4 = new Node;
    Node * n5 = new Node;

    n1->data = 1;
    n2->data = 1;
    n3->data = 0;
    n4->data = 0;
    n5->data = 1;

    test = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    
    n1 = n2 = n3 = n4 = n5 = nullptr;

    if (parity(test)) cout << "true" << endl;
    else  cout << "false" << endl;

    // go through the ll and deallocate the data
}

int main(){
    test();
    return 0;
}
