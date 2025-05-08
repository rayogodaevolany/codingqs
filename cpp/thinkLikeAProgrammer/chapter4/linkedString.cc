#include<iostream>
using namespace std;

struct Node {
	char character;
	Node * next;
};

typedef Node * characterArray;

void append(char character, characterArray head){
// append a character to end of array?
// loop till end of list but not NULL
	Node * pointer = head;
	while (pointer->next !=NULL){
		pointer = pointer->next;
	}
// now at end, append character
	Node * n = new Node;
	n->character = character;
	n->next = NULL;
	pointer->next = n;
	
	pointer = n = NULL;
}

char charAt(int index, characterArray head){
// give charater at the given index
	Node * pointer = new Node;
	pointer = head;
	for(int i=0;i<index;i++){
		pointer = pointer->next;
		
	}
	return pointer->character;
}

void print(characterArray head){
	Node * pointer = head;
	while (pointer !=NULL){
		cout << pointer->character;
		pointer = pointer->next;
	}
	cout << endl;
	
}

void cat(characterArray& head1, characterArray head2){
    // go to the end of head1
    Node * pointer = head1;
    while(pointer->next != NULL){
        pointer = pointer->next;
    }

    // copy each node of head2 and append the new node to head1
        if(head2->next == NULL) return;
        Node * str2Pointer = head2->next;
    while(str2Pointer != NULL){
        Node * newNode = new Node;
        // add the character from the second list
        newNode->character = str2Pointer->character;
        // make the end of the first list point to this new node
        pointer->next = newNode;
        // move the first pointer to its next value
        pointer = pointer->next;
        // move the second pointer to its next value
        str2Pointer = str2Pointer->next;
        newNode = NULL;
    }
    pointer->next = NULL;
}

// remove a certain amount of characters from a given index
void removeChar(characterArray head, int index, int length){
    if (head->next == NULL ) return;
    // create a pointer
    Node * pointer = head;
    // stop one node before the index node
    for(int i=0;i<index;i++){
        pointer = pointer->next;
    }
    // get to the node that is after the removal
    Node * slice = pointer->next;
    for(int i=0;i<length;i++){
        // make another pointer to slice
        Node * deallocate = slice;
        slice = slice->next;
        //deallocate node
        delete[] deallocate;

    }
    // connect the index point to the node after the given length
    pointer->next = slice;

}
void test(){
	// make strings
	// create new string with linkedlist
	characterArray hi = new Node;
	Node *n1 = new Node;
	Node *n2 = new Node;
	
	n1->character = 'h';
	n2->character= 'i';

	hi->next = n1;
	n1->next = n2;
	n2->next = NULL;

	n1 = n2 = NULL;

    //make hello string
    characterArray hello = new Node;
    Node *n3 = new Node;
    Node *n4 = new Node;
    Node *n5 = new Node;
    Node *n6 = new Node;
    Node *n7 = new Node;

    n3->character = 'h';
    n4->character = 'e';
    n5->character = 'l';
    n6->character = 'u';
    n7->character = 'o';

    hello->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n6;
    n6->next = n7;
    n7->next = NULL;

    n3 = n4 = n5 =n6 =n7 =NULL;

	print(hi);
	append('x', hi);
	cout << charAt(3, hi)<< endl;
	print(hi);
    print(hello);
    cat(hi, hello);
    print(hi);
    removeChar(hi,2,3);
    print(hi);


}

int main(){
	test();
    return 0;
}
