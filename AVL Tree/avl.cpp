#include <iostream>
using namespace std;

/*
## Logic of the Code:
- The code implements a Binary Search Tree (BST) with insertion, deletion, and tree printing functionalities.
- The `Node` class represents individual nodes in the BST with integer values and pointers to left and right child nodes.
- The `BST` class manages the BST with functions for inserting nodes, deleting nodes (using case 3 of BST deletion), finding the minimum value in a subtree, and printing the tree structure.
- The `Insert` function recursively inserts nodes into the BST based on their values.
- The `Case3Deletion` function handles the deletion of a node with two children by finding the inorder successor, replacing the node's value with the successor's value, and then recursively deleting the successor.
- The `minvalue` function finds the smallest node in a subtree.
- The `printTree` function prints the BST structure in a readable format, showing branches and nodes.
- In the `main` function, nodes are inserted into the BST, and then a node is deleted using the `Case3Deletion` function. The tree structure is printed before and after the deletion.
*/


// Structure to represent branches in the tree visualization
struct Trunk
{
    Trunk *prev;  // Pointer to the previous trunk
    string str;   // String to represent the trunk

    // Constructor for Trunk structure
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Helper function to print branches of the binary tree
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev);  // Recursively print previous trunks
    cout << p->str;
}

// Node class to represent each node in the binary search tree
class Node
{
private:
    int num;         // Value of the node
    Node *right;     // Pointer to the right child node
    Node *left;      // Pointer to the left child node

public:
    // Constructors
    Node() : right(NULL), left(NULL) {}  // Default constructor
    Node(int num) : num(num), right(NULL), left(NULL) {}  // Parameterized constructor

    // Friend class and function declaration to allow BST access to private members
    friend class BST;
    friend int main();
};

// Binary Search Tree class
class BST
{
private:
    Node *Root;  // Pointer to the root node of the BST

public:
    // Constructor
    BST() : Root(nullptr) {}

    // Function to insert a new node into the BST
    Node *Insert(Node *node, int num)
    {
        // If the current node is null, create a new node
        if (node == NULL)
        {
            Node *temp = new Node(num);
            if (Root == NULL)
            {
                Root = temp;  // Set the new node as the root if the tree is empty
            }
            return temp;
        }

        // Recursively insert into the left or right subtree
        if (num > node->num)
        {
            node->right = Insert(node->right, num);
        }
        else if (num < node->num)
        {
            node->left = Insert(node->left, num);
        }
        else
        {
            cout << "Already Exists!!! " << endl;  // Print a message if the value already exists
        }
        return node;
    }

    // Function to delete a node from the BST using case 3
    void Case3Deletion(Node *&node, int num)
    {
        // Check if the current node is NULL (base case for recursion)
        if (node == NULL)
        {
            cout << "Node not Found !!!" << endl;
            return;
        }

        // If the value to be deleted is less than the current node's value,
        // recursively delete from the left subtree
        if (num < node->num)
        {
            Case3Deletion(node->left, num);
        }
        // If the value to be deleted is greater than the current node's value,
        // recursively delete from the right subtree
        else if (num > node->num)
        {
            Case3Deletion(node->right, num);
        }
        // If the current node is the node to be deleted
        else
        {
            // If the current node has no left child, replace it with its right child
            if (node->left == NULL)
            {
                Node *temp = node->right;
                delete node;
                node = temp;
            }
            // If the current node has no right child, replace it with its left child
            else if (node->right == NULL)
            {
                Node *temp = node->left;
                delete node;
                node = temp;
            }
            // If the current node has both left and right children
            else
            {
                // Find the inorder successor (smallest node in the right subtree)
                Node *successor = minvalue(node->right);
                // Copy its value to the current node
                node->num = successor->num;
                // Recursively delete the inorder successor
                Case3Deletion(node->right, successor->num);
            }
            // Print a message indicating successful deletion
            cout << " The value " << num << " Deleted Successfully." << endl;
        }
    }

    // Function to find the minimum value node in a subtree
    Node *minvalue(Node *node)
    {
        if (node == NULL)
        {
            return NULL;
        }
        if (node->left == NULL)
        {
            return node;
        }
        return minvalue(node->left);
    }

    // Function to print the binary search tree (BST) in order
    void printTree(Node *root, Trunk *prev, bool isRight)
    {
        if (root == NULL)
            return;

        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);  // Print right subtree

        if (!prev)
            trunk->str = "---";
        else if (isRight)
        {
            trunk->str = ".---";
            prev_str = "   |";
        }
        else
        {
            trunk->str = "`---";
            prev->str = prev_str;
        }

        showTrunks(trunk);  // Print the trunk
        cout << root->num << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(root->left, trunk, false);  // Print left subtree
    }
};

int main()
{
    BST bl;

    // Insert nodes into the BST
    bl.Insert(bl.Root, 50);
    bl.Insert(bl.Root, 30);
    bl.Insert(bl.Root, 70);
    bl.Insert(bl.Root, 20);
    bl.Insert(bl.Root, 40);
    bl.Insert(bl.Root, 60);
    bl.Insert(bl.Root, 80);

    cout << endl;
    cout << "Before Deletion Using 3rd Case (using inOrder Traverser)" << endl;
    bl.printTree(bl.Root, NULL, false);
    cout << endl << endl;

    // Delete a node from the BST
    bl.Case3Deletion(bl.Root, 50);
    cout << endl;

    cout << "After Deletion Using 3rd Case (using inOrder Traverser)" << endl;
    bl.printTree(bl.Root, NULL, false);
    cout << endl;

    return 0;
}


