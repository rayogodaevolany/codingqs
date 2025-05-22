#include <iostream>
#include <unordered_map>
using namespace std;

struct Node {
    int data;
    Node * left;
    Node * right;

    // Constructor to initialize a new node
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};
typedef Node * treePtr;


pair<int, int> sumAndCount(treePtr root){
    // base case
    if (root == nullptr) return {0, 0};

    auto resLeft = sumAndCount(root->left);
    auto resRight = sumAndCount(root->right);

    // check current node
    return {resLeft.first + resRight.first + root->data,
        resLeft.second + resRight.second + 1};
}

// average, median, mode
float average(treePtr root){
    // get all nodes in the tree then add and divide by size
    auto res = sumAndCount(root);

    if (res.second != 0){
        // cast to float before division to prevent loss of data
        return  static_cast<float>(res.first) / res.second;
    } else {
        return 0;
    }
}

// float averageIter(treePtr root){
//     stack<Node *> s;
//     s.push(root);
//     float sum = 0;
//     int count = 0;
//     while (!s.empty()){
//         Node * currentNode = s.top(); s.pop();
//         sum += currentNode->data;
//         count++;
//         s.push(currentNode->left);
//         s.push(currentNode->right);
//     }
//     if (count > 0) return sum/count;
//     else return 0;
// }

// float delegate(treePtr root){
//     if (root == nullptr){
//         return 0;
//     }
   
// }
// writing the average function in a recursive way actually doesn't make sense
// because you have to get the sum and count of all of the nodes all at once before 
// applying the calculation


// return how many nodes in the binary tree was smaller than it
// int iterHelper(treePtr root){
    // create a stack and go through every value
    // if smaller increase count
// }
// iteratively traverse the binary tree and find the median
// int iterMedian(treePtr root){
    // need to find the number of nodes 
    // create stack and count the nodes

    // go to each value, see how many nodes are smaller than it
    // create a stack and look at every node

    // check if the numbers align with median

// }

//  ====================================================================================================

// count nodes
int countNode(treePtr root){
    // basecase
    if (root == nullptr){
        return 0;
    }
    int leftCount = countNode(root->left);
    int rightCount = countNode(root->right);

    return leftCount + rightCount + 1;
}

// count nodes that have smaller values
// duplicate values?

int numNodesSmaller(treePtr root, int val){
    if (root == nullptr) {
        return 0;
    }
    
    int leftCount = numNodesSmaller(root->left, val);
    int rightCount = numNodesSmaller(root->right, val);

    // if root is greater than val
    if (root->data > val){
        return leftCount + rightCount;

    // if root is less than val
    } else if (root->data < val){
        // increment by 1
        return leftCount + rightCount + 1;
    } else {
        // it is duplicate
        return leftCount + rightCount;
    }

}

// traverse nodes, checking each nodes value to see how many nodes
// are less than it, if this value is equal to the median index then
// return
pair<int, bool> median(treePtr specificNode, treePtr root, int medianIndex){
    // basecase 
    if (specificNode == nullptr){
        return { 0, false};
    }
    auto resLeft = median(specificNode->left, root, medianIndex);
    auto resRight = median(specificNode->right, root, medianIndex);

    // check result of recursive call in case median was already found
    if (resLeft.second) {
        return {resLeft.first, resLeft.second};
    } else if (resRight.second) {
        return {resRight.first, resRight.second};
    }

    // check current node
   int compare = numNodesSmaller(root, specificNode->data); 
   if ((compare + 1) == medianIndex){
       return {specificNode->data, true};
   } else {
       return {0, false};
   }


}

// i realized that the median of a even number is the 
// average of the two in the middle
float medianWrapper(treePtr root){
    int count = countNode(root);
    int medianIndex;
    pair <int, bool> res;
    if (count % 2 == 1){
        // fix rounding down
        medianIndex = (count / 2) + 1;
        res = median(root, root, medianIndex);

    // get average of both
    } else {
        // first median
        medianIndex = (count / 2);
        res = median(root, root, medianIndex);

        // store first median in tmp
        auto tmp = res;

        // look for second median
        medianIndex = (count / 2)+ 1;
        res = median(root, root, medianIndex);

        // if both are successful
        if (tmp.second && res.second){
            res.first = (static_cast<float>(tmp.first) + res.first)/ 2;

        // if either of the medians fails then return 0
        } else {
            return 0;
        }
    }
    
    if (res.second) return res.first;
    else return 0;
}

// find the most frequent value?
// int mode(treePtr root){
//     // create a hashmap
//     // for each value keep a counter
//     // loop through entire tree
//     // loop through hashmap to see which value appeared the most
//     return 0;
// }


//  ====================================================================================================

// try to find the mode using recursion


// recurse over entire tree adding each node's value to a hashmap
int modeMap(treePtr root, unordered_map<int, int>& hashmap){
    // basecase
    if (root == nullptr) return 0;
    // call recursively and pass on hashmap
    // add current node to hashmap
    return 0;
}

int modeWrapper(treePtr root){
    // make hashmap
    unordered_map<int, int> hashmap;
    // fill out hashmap
     modeMap(root, hashmap);

     int most;
     int count = 0;
     // iterative version
     for (auto it : hashmap){
         if (it.second > count){
             count = it.second;
             most = it.first;
         }
     }
     // recurse over hashmap
     // return value
     return most;
}

//  ====================================================================================================

treePtr createNode(int data) {
    Node* newNode = new Node(data); // Assumes C++ new operator for allocation
    return newNode;
}

treePtr buildTestTree() {
    treePtr root = createNode(20);

    root->left = createNode(10);
    root->right = createNode(30);

    root->left->left = createNode(5);
    root->left->right = createNode(15);

    root->right->left = createNode(25);
    root->right->right = createNode(35);

    root->left->right->left = createNode(3); // 3 is the left child of 15

    return root;
}

void test() {
    Node * testTree = buildTestTree();
    float avg =  average(testTree);
    int medianTest = medianWrapper(testTree);
    cout << avg << " " << medianTest <<  endl;


}

int main(){
    test();
    return 0;
}
