#include <iostream>

// Node definition for the binary search tree
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Class for binary search tree
class BinarySearchTree {
private:
    Node* root; // Root node of the binary search tree

public:
    // Constructor
    BinarySearchTree() : root(nullptr) {}

    // Function to count nodes at a given height in a binary search tree
    int countNodesAtHeight(int targetHeight, int currentHeight = 0) {
        return countNodesAtHeight(root, targetHeight, currentHeight);
    }

private:
    // Private recursive function to count nodes at a given height
    int countNodesAtHeight(Node* root, int targetHeight, int currentHeight) {
        if (root == nullptr) {
            return 0; // Base case: empty subtree
        }

        // If the current height matches the target height, count this node
        if (currentHeight == targetHeight) {
            return 1; // Base case: node at target height
        }

        // Recursively count nodes in the left and right subtrees
        return countNodesAtHeight(root->left, targetHeight, currentHeight + 1) +
               countNodesAtHeight(root->right, targetHeight, currentHeight + 1);
    }
};

// Example usage
int main() {
    BinarySearchTree bst;
    // Assuming 'root' is the root of your binary search tree
    // int height = /* height of the tree, precomputed and stored */;
    int targetHeight = /* the height at which you want to count nodes */;

    int count = bst.countNodesAtHeight(targetHeight);
    std::cout << "Number of nodes at height " << targetHeight << ": " << count << std::endl;

    return 0;
}
