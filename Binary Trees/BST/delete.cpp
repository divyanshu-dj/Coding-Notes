Node* deleteFromBST(Node* &root, int val) {
  if(root == NULL)
    return root;
  
  //For finding the node containg val
  if(root->data == val) {
    //0 child
    if(root->left == NULL && root->right == NULL) {
      delete root;
      return NULL;
    }

    //1 child
    //left child exists
    if(root->left != NULL && root->right == NULL) {
      Node* temp = root->left;
      delete root;
      return temp;
    }

    //right child exists
    if(root->left == NULL && root->right != NULL) {
      Node* temp = root->right;
      delete root;
      return temp;
    }

    //2 child
    if(root->left != NULL && root->right != NULL) {
      int mini = minVal(root->right)->data;
      root->data = mini;
      root->right = deleteFromBST(root->right, mini);
      return root;
    }
      
  }

    
  else if(val > root->data) {
    root->right = deleteFromBST(root->right, val);
    return root;
  }
  else {
    root->left = deleteFromBST(root->left, val);
    return root;
  }
}
