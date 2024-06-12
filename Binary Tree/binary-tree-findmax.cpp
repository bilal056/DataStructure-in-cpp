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

    // Function to find the maximum value node in a binary tree
    int findMaxNode(node* curr) {
        if (curr == NULL) {
            return INT_MIN;  // Return the smallest possible integer if the node is null
        }

        int maxValue = curr->info;
        int leftMax = findMaxNode(curr->left);
        int rightMax = findMaxNode(curr->right);

        if (leftMax > maxValue) {
            maxValue = leftMax;
        }
        if (rightMax > maxValue) {
            maxValue = rightMax;
        }

        return maxValue;
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

    // Find the maximum node value in the binary tree
    cout << "Maximum node value in the binary tree is: " << tree.findMaxNode(tree.root) << endl;

    return 0;
}
