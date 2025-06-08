#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};
typedef  Node * listPtr;

int sum(listPtr head){
    if (head == nullptr) return 0;
    int rest = sum(head->next);
    if (head->data > 0) rest += head->data;
    return rest;
}

void test(){
    listPtr test;
    Node * n1 = new Node;
    Node * n2 = new Node;
    Node * n3 = new Node;
    Node * n4 = new Node;
    Node * n5 = new Node;

    n1->data = -5;
    n2->data = 34;
    n3->data = -2;
    n4->data = 7;
    n5->data = 29;

    test = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    
    n1 = n2 = n3 = n4 = n5 = nullptr;

    cout << sum(test) << endl;
}

int main(){
    test();
    return 0;
}
