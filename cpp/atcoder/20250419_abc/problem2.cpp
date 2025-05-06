#include<iostream>
#include<queue>
using namespace std;

// process orders
int main(){

    int num;
    //get num of orders
    cin >> num;
    
    // create queue 
    queue<int> q;
    
    int head, menu, popped;
    // while loop on num of orders
    while (num){
        // get first val
        cin >> head;
        if (head == 1) {
        //if the line starts with 1 then add to queue
            cin >> menu;
            q.push(menu);
        } else {
            //if the line starts with 2 then pop from queue
            popped = q.front();
            q.pop();
               // print popped value 
            cout<<popped << endl;
        }
        
        // decrement while loop
        num--;
    }
    
    return 0;
}
