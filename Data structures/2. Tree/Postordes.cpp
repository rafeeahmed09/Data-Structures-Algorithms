#include <iostream>
#include <vector>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node* Buildtree(vector<int> &post, int &idx){
    idx++;
    if (post[idx] == -1)
    {
        return NULL;
    }
    Node* root = new Node(post[idx]);
    root->left = Buildtree(post, idx);
    root->right = Buildtree(post, idx);

    return root;
}

void postOrder(Node* root){
    if (root == NULL)
    {
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" ";
    
}


int main() {
    vector<int> post = {1, 2,-1,-1,3,4,-1,-1,5,-1,-1};
    int idx = -1;
    Node* root =  Buildtree(post, idx);
    postOrder(root);

    cout<<endl;

    return 0;
}