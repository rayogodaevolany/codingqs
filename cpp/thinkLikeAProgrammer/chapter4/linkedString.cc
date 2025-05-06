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

	print(hi);
	append('x', hi);
	cout << charAt(3, hi)<< endl;
	print(hi);


}

int main(){
	test();
    return 0;
}
