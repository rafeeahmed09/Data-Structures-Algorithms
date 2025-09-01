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

// Traversal Algorithm.
// 1. preOrder.

void preOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    vector<int> preorder{1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    Node *root = Buildtree(preorder);

    preOrder(root);

    cout << endl;

    return 0;
}