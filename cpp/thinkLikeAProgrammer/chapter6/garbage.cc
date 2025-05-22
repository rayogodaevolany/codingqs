bool bst::checkBST(treePtr root){
    // basecase
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    // get rest of the data
    bool leftBool = checkBST(root->left);
    bool rightBool = checkBST(root->right);

    // check nodes for bst properties
    if (root->right == nullptr){
        return root->left->data < root->data
            && leftBool;
    } else if (root->left == nullptr){
        return root->data < root->right->data 
            && rightBool;
    } else {
        return (root->left->data < root->data 
                && root->data < root->right->data) 
                && leftBool
                && rightBool;
    }

}


bool bst::checkBSTRefactored(treePtr root){
    // basecase
    if (root == nullptr) return true;
    if (root->left == nullptr && root->right == nullptr) {
        return true;
    }
    // get rest of the data
    bool leftBool = checkBSTRefactored(root->left);
    bool rightBool = checkBSTRefactored(root->right);


    bool currentLeft = (root->left == nullptr) 
        || root->left->data < root->data;
    bool currentRight = (root->right == nullptr)
        || root->right->data > root->data;

    if (!currentLeft || !currentRight) return false;
    else return leftBool && rightBool;
}

bool bst::checkBSTImproved(treePtr root){
    // basecase
    if (root == nullptr) return true;

    // check nodes for bst properties
    bool leftBool = (root->left == nullptr) 
        || root->left->data < root->data;
    bool rightBool = (root->right == nullptr)
        || root->right->data > root->data;

    if (!leftBool || !rightBool){
        return false;
    }

    // return recursive calls
    return checkBSTImproved(root->left) && checkBSTImproved(root->right);

}



