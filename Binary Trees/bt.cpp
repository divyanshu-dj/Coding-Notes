#include <iostream>
using namespace std;

// node implementation
class node {
    public:
        int data;
        node* left;
        node* right;

    node(int data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

// function to build tree
node* buildTree(node* root) {
    cout<<"Enter data: "<<endl;
    int data;
    cin>>data;
    root = new node(data);

    if(data == -1)
        return NULL;

    cout<<"Enter left child of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right child of "<<data<<endl;
    root->right = buildTree(root->right);

}

int main()
{
    node* root = NULL;
    root = buildTree(root);
    return 0;
}
