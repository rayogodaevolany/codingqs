#include <iostream>
using namespace std;

struct Node{
    int data;
    Node * next;
};
typedef  Node * listPtr;

listPtr sort(listPtr head){
    // basecase
    if (head == nullptr) return nullptr;
    if (head->next == nullptr) return head;
    // get the rest of the sorted list
    listPtr sorted  = sort(head->next);

    Node * pointer = sorted->next;
    Node * trailer = sorted;

    if (head->data < trailer->data){
        head->next = sorted;
        return head;
    } else {
        while (pointer != nullptr && head->data > pointer->data){
            pointer = pointer->next;
            trailer = trailer->next;
        }
        trailer->next = head;
        head->next = pointer;
        return sorted;
    }
}


void test(){
    listPtr test;
    Node * n1 = new Node;
    Node * n2 = new Node;
    Node * n3 = new Node;
    Node * n4 = new Node;
    Node * n5 = new Node;

    n1->data = 121;
    n2->data = 1;
    n3->data = -30;
    n4->data = 50;
    n5->data = 11;

    test = n1;
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = nullptr;
    
    n1 = n2 = n3 = n4 = n5 = nullptr;


    listPtr sorted = sort(test);
    Node * pointer = sorted;
    while( pointer != nullptr){
        cout << pointer->data << endl;
        pointer = pointer->next;
    }
    // go through the ll and deallocate the data
}


int main(){
    test();
    return 0;
}
