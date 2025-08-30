#include <iostream>
#include <vector>
using namespace std;
// defines a basic building block for a binary tree. This structure
// is used to create a tree data structure, which is a hierarchical collection of nodes.

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

static int idx = -1;
Node *Buildtree(vector<int> &perorder)
{
    idx++;
    if (perorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(perorder[idx]);
    root->left = Buildtree(perorder);
    root->right = Buildtree(perorder);

    return root;
}
int main()
{

    vector<int> perorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = Buildtree(perorder);
    cout << root->data << endl;
    cout << root->left->data  << endl;
    cout << root->right->data << endl;

    return 0;
}