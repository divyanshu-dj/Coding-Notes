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

void buildFromLevelOrder(node* &root) {
    queue<node*> q;

    cout << "Enter data for root" << endl;
    int data ;
    cin >> data;
    root = new node(data);
    
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left node for: " << temp->data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp->left);
        }

        cout << "Enter right node for: " << temp->data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp->right);
        }
    }
 }


int main()
{
    node* root = NULL;
    root = buildTree(root);
    return 0;
}
