Node* insertIntoBST(Node * &root, int d) {
  if(root == NULL){
    root = new Node(d);
    return root;
  }

  if( d > root->data ) {
    root->right = insertIntoBST(root->right, d);
  }
  else {
    root->left = insertIntoBST(root->left, d);
  }
}

void takeInput(Node* &root) {
  int data;
  cin>>data;

  while(data != -1) {
    root = insetIntoBST(root, data);
    cin>>data;
  }
}

int main() {
  Node* root = NULL;
  takeInput(root);
  return 0;
}
