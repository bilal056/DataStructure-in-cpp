#include <iostream>
using namespace std;

// Node class for creating nodes of the binary search tree
class Node
{
private:
    int data;    // Data stored in the node
    Node *right; // Pointer to the right child node
    Node *left;  // Pointer to the left child node

public:
    // Constructors
    Node()
    {
        this->data = 0;
        right = left = nullptr;
    }
    Node(int val)
    {
        data = val;
        right = left = nullptr;
    }

    // Friend class and function declaration to allow BST access to private members
    friend class BST;
    friend int main();
};

// Binary Search Tree (BST) class
class BST
{
private:
    Node *Root; // Pointer to the root node of the BST

public:
    // Constructor to initialize the root as nullptr
    BST()
    {
        this->Root = nullptr;
    }
    friend int main();

    // Insert function to insert a new node in the BST
    Node *Insert(Node *node, int val)
    {
        // If the node is nullptr, create a new node with the given value
        if (node == NULL)
        {
            Node *temp = new Node(val);
            // If the tree is empty, set the new node as the root
            if (Root == NULL)
            {
                Root = temp;
            }
            return temp;
        }

        // If the value is greater than the current node's data, insert in the right subtree
        if (val > node->data)
        {
            node->right = Insert(node->right, val);
        }
        // If the value is smaller than the current node's data, insert in the left subtree
        else if (val < node->data)
        {
            node->left = Insert(node->left, val);
        }
        // If the value already exists in the BST, print a message
        else
        {
            cout << "Already Exists!!! " << endl;
        }
        return node;
    }

    // Pre-order traversal of the BST (root-left-right)
    void preOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }

    // In-order traversal of the BST (left-root-right)
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

    // Post-order traversal of the BST (left-right-root)
    void postOrder(Node *node)
    {
        if (node == NULL)
        {
            return;
        }

        postOrder(node->left);
        postOrder(node->right);
        cout << node->data << " ";
    }

    // Search function to find a value in the BST
    int findSmallest(Node *node)
    {
        if (node == NULL)
        {
            cerr << "BST is empty." << endl;
            return -1; // Assuming -1 represents an error or invalid value
        }

        Node *current = node;
        while (current->left != NULL)
        {
            current = current->left;
        }
        return current->data;
    }

    // Function to count the total number of nodes in the BST
    int countNodes(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }

        return 1 + countNodes(node->left) + countNodes(node->right);
    }

    // Function to display a menu for BST operations
    void menu()
    {
        int choose = -1;
        while (choose != 0)
        {
            cout << " __________________________________" << endl;
            cout << "|- Insertion and traversal in BST -|" << endl;
            cout << "| 1. Insert New Node In BST        |" << endl;
            cout << "| 2. Pre-order Traversal           |" << endl;
            cout << "| 3. In-order Traversal            |" << endl;
            cout << "| 4. Post-order Traversal          |" << endl;
            cout << "| --- Other Functions ---           |" << endl;
            cout << "| 5. Find Smallest Value In BST    |" << endl;
            cout << "| 6. Count Nodes In BST            |" << endl;
            cout << "| 0. EXIT.                         |" << endl;
            cout << " __________________________________ " << endl;
            cin >> choose;

            switch (choose)
            {
            case 1:
                int insert;
                cout << "----------------------------" << endl;
                cout << "Insert a number into the tree:" << endl;
                cin >> insert;
                Insert(Root, insert);
                cout << "----------------------------" << endl;
                break;
            case 2:
                cout << "----------------------------" << endl;
                cout << "Pre-order traversal:" << endl;
                preOrder(Root);
                cout << endl;
                cout << "----------------------------" << endl;
                break;
            case 3:
                cout << "----------------------------" << endl;
                cout << "In-order traversal:" << endl;
                inOrder(Root);
                cout << endl;
                cout << "----------------------------" << endl;
                break;
            case 4:
                cout << "----------------------------" << endl;
                cout << "Post-order traversal:" << endl;
                postOrder(Root);
                cout << endl;
                cout << "----------------------------" << endl;
                break;
            case 5:
                cout << "----------------------------" << endl;
                cout << "Smallest number in the tree: ";
                cout << findSmallest(Root) << endl;
                cout << "----------------------------" << endl;
                break;
            case 6:
                cout << "----------------------------" << endl;
                cout << "Count nodes in the tree:" << endl;
                cout << "Total number of nodes: " << countNodes(Root) << endl;
                cout << "----------------------------" << endl;
                break;
            default:
                cout << "THANK YOU FOR USING THIS PLATFORM..." << endl;
                break;
            }
        }
    }
};

// Main function to demonstrate the BST operations
int main()
{
    BST Tree;
    Tree.menu(); // Display menu for BST operations
    return 0;
}
