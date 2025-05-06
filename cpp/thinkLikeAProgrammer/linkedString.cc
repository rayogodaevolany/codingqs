#include<iostream>
using namespace std;

struct Node {
	char character;
	Node * next;
}

typedef Node * characterArray;

void append(char character, characterArray head){
// append a character to end of array?
// loop till end of list
	Node * pointer = str;
	while (pointer !=NULL){
		pointer->pointer.next;
	}
// now at end, append character
	Node * n = new Node;
	n->charcter = character;
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

void print(characterArray str){
	Node * pointer = str;
	while (pointer !=NULL){
		cout << str.char;
		pointer->pointer.next;
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
	cout << charAt(2, hi);
	append('i', hi);
	print(hi);

}
int main(){
	test();
}
