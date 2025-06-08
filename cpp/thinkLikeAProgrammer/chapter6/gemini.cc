void iterativeInsert(treePtr root, Node * newNode){ // PROBLEM 1: root is passed by value
    if (root == nullptr) { // This attempts to handle empty tree
        root = newNode;    // This only changes the local copy of root, not the actual tree root
        return;
    }
    stack<Node *> s;
    s.push(root);
    while (!s.empty()){
        Node * currentNode = s.top(); s.pop();

        // if both are null (currentNode is a leaf)
        if (currentNode->left == nullptr && currentNode->right == nullptr){
            // PROBLEM 2: Incorrect comparison logic for placement
            if (currentNode->data < newNode->data){ // If newNode is greater than current
                currentNode->left = newNode; // Incorrect: Should go to the right
            } else if (currentNode->data > newNode->data){ // If newNode is smaller than current
                currentNode->right = newNode; // Incorrect: Should go to the left
            }
            // PROBLEM 3: Missing return/break; if insertion happens, loop should stop.
            // Also, what if newNode->data == currentNode->data (duplicate)?

        // if only left child exists (or right child is the null spot)
        } else if (currentNode->right == nullptr){
            // PROBLEM 4: Misses opportunity to insert if newNode fits as right child.
            // It only pushes the left child for further processing.
            s.push(currentNode->left);

        // if only right child exists (or left child is the null spot)
        } else if (currentNode->left == nullptr) {
            // PROBLEM 4: Misses opportunity to insert if newNode fits as left child.
            // It only pushes the right child for further processing.
            s.push(currentNode->right);
        } else { // Node has both children
            // This part correctly decides which path to explore next
            if (currentNode->data < newNode->data){ // newNode is greater
                s.push(currentNode->right);
            } else if (currentNode->data > newNode->data){ // newNode is smaller
                // Comment "go right" is a typo, code pushes left, which is correct here
                s.push(currentNode->left);
            }
            // What if newNode->data == currentNode->data (duplicate)?
        }
    }
    return;
}