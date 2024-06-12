#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    int height;

    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
};

class BST
{
public:
    Node *root;

    BST()
    {
        root = NULL;
    }

    // Function to get the height of a node
    int getHeight(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return node->height;
    }

    // Function to calculate the balance factor of a node
    int getBalance(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return getHeight(node->left) - getHeight(node->right);
    }

    // Function to insert a new node into the BST
    Node* insert(Node* node, int key)
    {
        if (node == NULL)
        {
            return new Node(key);
        }

        if (key < node->data)
        {
            node->left = insert(node->left, key);
        }
        else if (key > node->data)
        {
            node->right = insert(node->right, key);
        }
        else
        {
            return node; // No duplicate keys allowed
        }

        // Update the height of the current node
        node->height = 1 + max(getHeight(node->left), getHeight(node->right));

        return node;
    }
};

int main()
{
    BST tree;
    tree.root = tree.insert(tree.root, 15);
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 5);

    // Print the balance factors of specific nodes
    cout << "Balance of root node: " << tree.getBalance(tree.root) << endl;
    cout << "Balance of left node: " << tree.getBalance(tree.root->left) << endl;
    cout << "Balance of right node: " << tree.getBalance(tree.root->right) << endl;
    cout << "Balance of left-left node: " << tree.getBalance(tree.root->left->left) << endl;

    return 0;
}
