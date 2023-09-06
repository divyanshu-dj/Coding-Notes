int height(node* root) {
  if(root==NULL) return 0;

  int left = height(root->left);
  int right = height(root->right);

  return max(left,right)+1;
}
