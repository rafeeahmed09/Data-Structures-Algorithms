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

// Build tree from preorder traversal with -1 as NULL marker
node* build(vector<int> &tree, int &idx) {
    if (idx >= (int)tree.size() || tree[idx] == -1) {
        idx++;
        return NULL;
    }

    node* root = new node(tree[idx]);
    idx++;
    root->left = build(tree, idx);
    root->right = build(tree, idx);

    return root;
}

// Lowest Common Ancestor
node* LCA(node* root, node* p , node* q) {
    if (root == NULL) return NULL;
    if (root == p || root == q) return root;
    
    node* leftLCA = LCA(root->left, p, q);
    node* rightLCA = LCA(root->right, p, q);

    if (leftLCA != NULL && rightLCA != NULL) {
        return root;
    }
    return (leftLCA != NULL) ? leftLCA : rightLCA;
}

// Find a node with given value
node* findNode(node* root, int val) {
    if (root == NULL) return NULL;
    if (root->data == val) return root;
    node* left = findNode(root->left, val);
    if (left != NULL) return left;
    return findNode(root->right, val);
}

int main() {
    vector<int> tree_vec = {1, 2, 4, -1, -1, 5, -1, -1, 3, -1, -1};
    int index = 0;

    // Build the tree
    node* root = build(tree_vec, index);
    
    // Example: Find LCA of 4 and 5
    node* p = findNode(root, 4);
    node* q = findNode(root, 5);

    if (p && q) {
        node* lca = LCA(root, p, q);
        if (lca) {
            cout << "LCA of " << p->data << " and " << q->data 
                 << " is: " << lca->data << endl;
        } else {
            cout << "LCA not found." << endl;
        }
    } else {
        cout << "One or both nodes not found in the tree." << endl;
    }

    return 0;
}
