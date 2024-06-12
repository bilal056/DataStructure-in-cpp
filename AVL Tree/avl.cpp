#include <iostream>
using namespace std;

/*
Logic of the code:

1. The code defines a Trunk struct for visual representation of the tree's branches during printing.
2. The Node class represents each node in the AVL tree, storing data, pointers to left and right children, and the height of the node.
3. The AVL class handles the AVL tree operations, including inserting nodes, updating heights, calculating balance factors, and performing rotations to keep the tree balanced.
4. The insert function recursively adds a new value to the tree, updates the height of nodes, and performs necessary rotations to balance the tree.
5. The rightRotate and leftRotate functions perform the required rotations to maintain the AVL tree balance.
6. The printTree function, along with showTrunks, visually represents the tree structure with balance factors.
7. The main function creates an instance of the AVL tree, inserts values into it, and displays the tree.

*/




// Trunk struct is used to assist in visual representation of the tree
struct Trunk
{
    Trunk *prev; // Pointer to the previous trunk in the chain
    string str;  // String to be printed for the trunk

    // Constructor to initialize trunk with previous trunk and string
    Trunk(Trunk *prev, string str)
    {
        this->prev = prev;
        this->str = str;
    }
};

// Function to print all the trunks in the chain
void showTrunks(Trunk *p)
{
    if (p == NULL)
        return;

    showTrunks(p->prev); // Recursive call to print the previous trunk
    cout << p->str;      // Print the current trunk's string
}

// Node class representing each node in the AVL tree
class Node
{
public:
    int data;    // Data stored in the node
    Node *left;  // Pointer to the left child
    Node *right; // Pointer to the right child
    int height;  // Height of the node

    // Constructor to initialize a new node with given value
    Node(int val)
    {
        data = val;
        left = right = NULL;
        height = 1;
    }
    friend int main(); // Friend function declaration to access private members of Node
};

// AVL class representing the AVL tree and its operations
class AVL
{
private:
    Node *root; // Pointer to the root of the AVL tree

public:
    // Constructor to initialize an empty AVL tree
    AVL()
    {
        root = NULL;
    }
    friend int main(); // Friend function declaration to access private members of AVL

    // Function to insert a new value into the AVL tree and balance it
    Node *insert(Node *node, int num)
    {
        // If the node is NULL, create a new node with the given value
        if (node == NULL)
        {
            Node *temp = new Node(num);
            if (root == NULL)
            {
                root = temp; // Set root to the new node if tree is empty
            }
            return temp;
        }

        // Recur down the tree to insert the value in the correct position
        if (num < node->data)
        {
            node->left = insert(node->left, num);
        }
        else if (num > node->data)
        {
            node->right = insert(node->right, num);
        }

        // Update the height of the current node
        node->height = Update_height(node);
        int balance = getBalance(node); // Get the balance factor of the node

        // Perform rotations to balance the node if needed
        if (balance > 1)
        {
            if (num < node->right->data)
            {
                node->right = rightRotate(node->right);
            }
            return leftRotate(node);
        }
        else if (balance < -1)
        {
            if (num > node->left->data)
            {
                node->left = leftRotate(node->left);
            }
            return rightRotate(node);
        }

        return node; // Return the balanced node
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

    // Function to update the height of a node based on its children's heights
    int Update_height(Node *node)
    {
        if (node == nullptr)
        {
            return 0;
        }

        int leftHeight = getHeight(node->left);
        int rightHeight = getHeight(node->right);

        return 1 + ((leftHeight > rightHeight) ? leftHeight : rightHeight);
    }

    // Function to get the balance factor of a node
    int getBalance(Node *node)
    {
        if (node == NULL)
        {
            return 0;
        }
        return getHeight(node->right) - getHeight(node->left);
    }

    // Function to perform a right rotation on a node
    Node *rightRotate(Node *y)
    {
        Node *x = y->left;
        Node *T = x->right;

        x->right = y;
        y->left = T;

        y->height = Update_height(y);
        x->height = Update_height(x);

        return x;
    }

    // Function to perform a left rotation on a node
    Node *leftRotate(Node *x)
    {
        Node *y = x->right;
        Node *T = y->left;

        y->left = x;
        x->right = T;

        x->height = Update_height(x);
        y->height = Update_height(y);

        return y;
    }

    // Function to print the AVL tree with trunks
    void printTree(Node *root, Trunk *prev, bool isRight)
    {
        if (root == NULL)
            return;

        string prev_str = "    ";
        Trunk *trunk = new Trunk(prev, prev_str);

        printTree(root->right, trunk, true);

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

        showTrunks(trunk);
        cout << root->data << " (Balance: " << getBalance(root) << ")" << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }

    // Wrapper function to insert a value into the AVL tree
    void insert(int val)
    {
        root = insert(root, val);
    }

    // Function to display the AVL tree
    void display()
    {
        printTree(root, NULL, false);
    }
};

int main()
{
    AVL A;

    A.insert(15);
    A.insert(20);
    A.insert(30);

    cout << endl;
    A.display();

    return 0;
}


