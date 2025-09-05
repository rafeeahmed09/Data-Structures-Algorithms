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
Node *Builtidorder(vector<int> &inorder)
{
    idx++;
    if (inorder[idx] == -1)
    {
        return NULL;
    }

    Node *root = new Node(inorder[idx]);
    root->left = Builtidorder(inorder);
    root->right = Builtidorder(inorder);

    return root;
}
// 2. InOder traversal.
void inOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    inOrder(root->left);
    cout << root->data << " ";
    inOrder(root->right);
}

int main()
{
    vector<int> inorder = {1, 2, -1, -1, 3, 4, -1, -1, 5, -1, -1};
    int idx = -1;
    Node *root = Builtidorder(inorder);

    inOrder(root);
    cout << endl;

    return 0;
}