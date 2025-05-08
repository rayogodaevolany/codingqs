#include<iostream>
using namespace std;

// struct for linkedInt
struct Node {
    int num;
    Node * next;
};

// typedef for head
typedef Node * linkedInt;

// intToList routine
linkedInt intToList(int num){
    // create new list
    linkedInt head = new Node;
    // new pointer
    Node * pointer = head;
    // get digits 
    while (num !=0){

        Node * newNode = new Node;
        newNode->num = num%10;
        // int division(math floor)
        num = num/10;

        // add digits to linkedList
            // connect to linkedlist
            pointer->next = newNode;
            // move pointer to next
            pointer = pointer->next;
        newNode = NULL;
    }
    pointer->next = NULL;
    pointer = NULL;
    return head;
    // return linkedInt
}

//routine that sums to linkedInts
linkedInt sum(linkedInt first, linkedInt second){
    // create new list
    linkedInt sumList = new Node;
    // pointer for traversing
    Node * pointer = sumList;
    // pointers for the two lists that will be added
    Node * p1 = first->next;
    Node * p2 = second->next;
    // carry variable starts at zero
    int carry = 0;

    // add the numbers one at a time
    // the cases where first and second are the same length or different lengths
    while(p1 != NULL){
        Node * newNode = new Node;
        int digitSum;

        if (p2 != NULL){
            digitSum = p1->num + p2->num + carry;
            carry = 0;
            if ((digitSum/10)% 10 != 0) {
                // carry the surplus
                carry = digitSum/10;
            }
            // the node has one digit
            newNode->num = digitSum % 10;
            pointer->next = newNode;
            pointer = pointer->next;
            newNode = NULL;
            p2 = p2->next;
        } else {
            digitSum = p1->num + carry;
            carry = 0;
            if ((digitSum/10)% 10 != 0) {
                // carry the surplus
                carry = digitSum/10;
            }
            newNode->num = digitSum % 10;
            pointer->next = newNode;
            pointer = pointer->next;
            newNode = NULL;
        }
        p1 = p1->next;

    }

    while(p2 != NULL){
        Node * newNode = new Node;
        int digitSum;
        digitSum = p2->num + carry;
        carry = 0;
        if ((digitSum/10)% 10 != 0) {
            // carry the surplus
            carry = digitSum/10;
        }
        newNode->num = digitSum % 10;
        pointer->next = newNode;
        pointer = pointer->next;
        newNode = NULL;
        p2 = p2->next;
    }
    pointer->next = NULL;
    pointer = NULL;

    return sumList;
}

void print(linkedInt head){
	Node * pointer = head->next;
	while (pointer != NULL){
		cout << pointer->num;
		pointer = pointer->next;
	}
	cout << endl;
}
void test(){
    int num = 1498;
    linkedInt linkedNum;
    linkedNum = intToList(num);
    print(linkedNum);

    int num2 = 28;
    linkedInt linkedNum2;
    linkedNum2 = intToList(num2);
    print(linkedNum2);

    linkedInt sumOfTwo;
    sumOfTwo = sum(linkedNum, linkedNum2);
    print(sumOfTwo);

 

}
int main(){
    test();
    return 0;
}
