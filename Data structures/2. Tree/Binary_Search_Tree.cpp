#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *insertTnBST(node *root, int val)
{
    if (root == NULL)
    {
        return new node(val);
    }

    if (val < root->data)
    {
        root->left = insertTnBST(root->left, val);
    }
    else
    {
        root->right = insertTnBST(root->right, val);
    }
}

node *BuildBST(vector<int> arr)
{
    node *root = NULL;
    for (int val : arr)
    {
        root = insertTnBST(root, val);
    }

    return root;
}

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

bool Search(node *root, int key)
{
    if (root == NULL)
    {
        return false;
    }

    if (root->data == key)
    {
        return true;
    }

    if (key < root->data)
    {
        return Search(root->left, key);
    }
    else
    {
        return Search(root->right, key);
    }
}

int main()
{
    vector<int> arr = {3, 2, 1, 5, 6, 4};
    node *root = BuildBST(arr);
    cout << Search(root, 2) << endl;

    return 0;
}