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

    // Constructor to initialize the binary tree
    BinaryTree() {
        root = NULL;
    }

    // Function to find the parent of a given node in a binary tree
    // curr: Current node being checked
    // p: Node whose parent is to be found
    // par: Parent of the current node
    // Returns the parent node if found, otherwise NULL
    node* parent(node* curr, node* p, node* par) {
        if(curr == NULL)
            return NULL;

        if (curr == p) {
            return par; // Return the parent node when the current node is the given node
        } else {
            node *t = NULL;
            t = parent(curr->left, p, curr); // Recursively search in the left subtree
            if(t!= NULL)
                return t;
            else {
                t = parent(curr->right, p, curr); // Recursively search in the right subtree
                return t;
            }
        }
    }

    // Function to find the sibling of a given node in a binary tree
    // p: Node whose sibling is to be found
    // Returns the sibling node if found, otherwise NULL
    node* sibling(node* p) {
        node* par = parent(root, p, NULL); // Find the parent of the given node

        if (par->left == p) // If the given node is the left child, return the right child as sibling
            return par->right;
        else 
            return par->left; // If the given node is the right child, return the left child as sibling
    }
};

int main() {
    // Create a binary tree
    BinaryTree tree;
    tree.root = new node(5);
    tree.root->left = new node(10);
    tree.root->right = new node(2);
    tree.root->right->left = new node(3);
    tree.root->right->right = new node(9);
    tree.root->left->left = new node(20);
    tree.root->left->right = new node(7);

    // Find sibling
    node *sib = tree.sibling(tree.root->right->left); //sibling of 3 (which is 9)
    cout<<"Sibling of 3 is: "<<sib->info<<endl;

    return 0;
}
