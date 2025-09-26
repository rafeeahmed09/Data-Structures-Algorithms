#include <iostream>
#include <vector>
using namespace std;

class node {
public:
    int data;
    node *left;
    node *right;
    node(int val) {
        data = val;
        left = right = NULL;
    }
};

int findIndex(vector<int> &inorder, int left, int right, int val) {
    for (int i = left; i <= right; i++) {
        if (inorder[i] == val) return i;
    }
    return -1;
}

node* buildTree(vector<int> &preorder, vector<int> &inorder, int left, int right, int &idx) {
    if (left > right) return NULL;

    node* root = new node(preorder[idx]);
    int index = findIndex(inorder, left, right, preorder[idx]);
    idx++;  // move to next preorder element

    root->left = buildTree(preorder, inorder, left, index - 1, idx);
    root->right = buildTree(preorder, inorder, index + 1, right, idx);

    return root;  // ✅ must return root
}

node* build(vector<int> &preorder, vector<int> &inorder) {
    int preIdx = 0;
    return buildTree(preorder, inorder, 0, inorder.size() - 1, preIdx);
}

void printInorder(node* root) {
    if (!root) return;
    printInorder(root->left);
    cout << root->data << " ";
    printInorder(root->right);
}

int main() {
    vector<int> preorder = {1, 2, 4, 5, 3};
    vector<int> inorder  = {4, 2, 5, 1, 3};

    node* root = build(preorder, inorder);

    cout << "Inorder traversal of constructed tree: ";
    printInorder(root);
    cout << endl;

    return 0;
}
