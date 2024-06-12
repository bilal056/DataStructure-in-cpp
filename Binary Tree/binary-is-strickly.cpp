#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int value;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val) : value(val), left(nullptr), right(nullptr) {}
};

// Definition for a binary tree.
class BinaryTree {
public:
    TreeNode* root;

    // Constructor to initialize the binary tree with a root node
    BinaryTree(int val) {
        root = new TreeNode(val);
    }

    // Function to check if a binary tree is strictly binary (full binary tree)
    bool isStrictlyBinaryTree(TreeNode* curr) {
        // Base case: If the current node is null, return true
        if (!curr) return true;

        // If the node is a leaf node (has no children), return true
        if (!curr->left && !curr->right) return true;

        // If the node has both left and right children, recursively check the left and right subtrees
        if (curr->left && curr->right) return isStrictlyBinaryTree(curr->left) && isStrictlyBinaryTree(curr->right);

        // If the node has only one child (either left or right), return false
        return false;
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree(1);
    tree.root->left = new TreeNode(2);
    tree.root->right = new TreeNode(3);
    tree.root->left->left = new TreeNode(4);
    tree.root->left->right = new TreeNode(5);

    // Check if the tree is strictly binary
    cout << "Is the tree strictly binary (full binary tree)? " << (tree.isStrictlyBinaryTree(tree.root) ? "Yes" : "No") << endl;

    return 0;
}
