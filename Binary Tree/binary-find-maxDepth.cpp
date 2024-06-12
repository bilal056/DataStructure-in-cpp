#include <iostream>
using namespace std;

// Definition for a binary tree node.
class node {
public:
    int info;
    node* left;
    node* right;
    
    // Constructor to initialize the node
    node(int val) {
        info = val;
        left = NULL;
        right = NULL;
    }
};

// Definition for a binary tree.
class BinaryTree {
public:
    node* root;

    // Constructor to initialize the binary tree with a root node
    BinaryTree(int val) {
        root = new node(val);
    }

    // Function to find the maximum depth of the binary tree
    int maxDepth(node* curr) {
        if (curr == NULL) return -1;

        int lDepth = maxDepth(curr->left);
        int rDepth = maxDepth(curr->right);

        return max(lDepth, rDepth) + 1;
    }

    // Function to delete the entire binary tree
    void deleteTree(node* leaf) {
        if (leaf != NULL) {
            deleteTree(leaf->left);
            deleteTree(leaf->right);
            delete leaf;
        }
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree(5);
    tree.root->left = new node(10);
    tree.root->right = new node(2);
    tree.root->right->left = new node(3);
    tree.root->right->right = new node(9);
    tree.root->left->left = new node(20);
    tree.root->left->right = new node(7);

    // Depth of the tree
    cout << "Depth of the tree: " << tree.maxDepth(tree.root) << endl;

    // Delete the entire tree
    tree.deleteTree(tree.root);

    return 0;
}
