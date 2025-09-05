#include<iostream>
#include<vector>
using namespace std;

class node{
    public:
    int data;
    node* left;
    node* right;

    node(int val){
        data = val;
        left = right = NULL;
    }
};

static int idx = -1;

node* buildTre(vector<int>  &Tree){
    idx++;
    if ( Tree[idx] == -1)
    {
        return NULL;
    }
    node* root = new node(Tree[idx]);
    root->left = buildTre(Tree);
    root->right = buildTre(Tree);

    return root;
    
}

void Perorder(node* root){
    if (root == NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    Perorder(root->left);
    Perorder(root->right);
}

int sumTree(node* root){
    if (root == NULL)
    {
        return 0;
    }

    int leftsum = sumTree(root->left);
    int rightsum = sumTree(root->right);

    root->data += leftsum + rightsum;

    return root->data;
    
}

int main() {
    vector<int> Tree = {1,2,-1,-1,3,4,-1,-1,5,-1,-1};
    
    node* root = buildTre(Tree);

    cout<< "before conversion : ";
    Perorder(root);
    cout<<endl;

    sumTree(root);
    
    cout<< "after conversion : ";
    Perorder(root);
    cout<<endl;

    return 0;

    
}