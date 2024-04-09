#include <iostream>
using namespace std;

// Node class to represent each node in the binary search tree
class Node
{
private:
    int data;       // Data stored in the node
    Node *right;    // Pointer to the right child node
    Node *left;     // Pointer to the left child node

public:
    // Default constructor
    Node()
    {
        this->data = 0;
        right = left = NULL;
    }

    // Parameterized constructor to initialize the node with a given value
    Node(int val)
    {
        data = val;
        right = left = NULL;
    }

    // Declaring BST class as a friend to access private members
    friend class BST;
};

// Binary Search Tree (BST) class
class BST
{
private:
    Node *Root;     // Pointer to the root node of the BST

public:
    // Constructor to initialize the BST with a null root
    BST()
    {
        this->Root = NULL;
    }

    // Friend declaration to allow main function access to private members
    friend int main(); 

    // Recursive function to insert a value into the BST
    Node *Insert(Node *node, int val)
    {
        if (node == NULL)
        {
            Node *temp = new Node(val);
            if (Root == NULL)
            {
                Root = temp;
            }
            return temp;
        }

        if (val > node->data)
        {
            node->right = Insert(node->right, val);
        }
        else if (val < node->data)
        {
            node->left = Insert(node->left, val);
        }
        else
        {
            cout << "Already Exists!!! " << endl;
        }
        return node;
    }

    // Recursive function to perform an in-order traversal of the BST
    void inOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    // Recursive function to search for a value in the BST and print its value along with its left and right child values
    void search_InOrder(Node *node, int value)
    {
        if (node == NULL)
        {
            return;
        }

        search_InOrder(node->left, value);

        if (node->data == value)
        {
            cout << node->data << " ";
            if (node->left)
            {
                cout << node->left->data << " ";
            }
            if (node->right)
            {
                cout << node->right->data << " ";
            }

            return;
        }

        search_InOrder(node->right, value);
    }

};

// Main function to test the BST implementation
int main()
{
    BST bl;
    int Searching_value;

    // Inserting values into the BST
    bl.Insert(bl.Root, 4);
    bl.Insert(bl.Root, 2);
    bl.Insert(bl.Root, 6);
    bl.Insert(bl.Root, 1);
    bl.Insert(bl.Root, 3);
    bl.Insert(bl.Root, 5);
    bl.Insert(bl.Root, 7);

    // Printing the inorder traversal of the BST
    cout << "Inorder traversal:" << endl;
    bl.inOrder(bl.Root);
    cout << endl;

    // Asking the user for a value to search in the BST
    cout << " Enter a value to search: " << endl;
    cin >> Searching_value;

    // Searching for the value in the BST and printing it along with its left and right child values
    bl.search_InOrder(bl.Root, Searching_value); 

    return 0;
}
