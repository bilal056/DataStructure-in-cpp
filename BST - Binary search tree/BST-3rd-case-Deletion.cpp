#include <iostream>
using namespace std;



struct Trunk
{
    Trunk *prev;
    string str;

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

    showTrunks(p->prev);

    cout << p->str;
}

// Node class to represent each employee
class Node
{
private:
    int num;

    Node *right; // Pointer to the right child node
    Node *left;  // Pointer to the left child node

public:
    // Constructors
    Node()
    {

        right = left = NULL;
    }
    Node(int num)
    {
        this->num = num;

        right = left = NULL;
    }

    // Friend class and function declaration to allow BST access to private members
    friend class BST;
    friend int main();
};

// Binary Search Tree class
class BST
{
private:
    Node *Root; // Pointer to the root node of the BST

public:
    // Constructor
    BST()
    {
        this->Root = nullptr;
    }
    friend int main();

    // Function to insert a new employee into the BST
    Node *Insert(Node *node, int num)
    {
        // If the current node is null, create a new node
        if (node == NULL)
        {
            Node *temp = new Node(num);
            if (Root == NULL)
            {
                Root = temp;
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
            cout << "Already Exists!!! " << endl;
        }
        return node;
    }
    // apply deletion for all cases except case 3

    // Delete A Node From BST Tree
    // Function to delete a node from the BST using the 3rd case
    // The function takes a reference to the node pointer and the value to be deleted
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

    // for Inorder travers (finding minimum value from right tree )
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
        cout << root->num << endl;

        if (prev)
            prev->str = prev_str;
        trunk->str = "   |";

        printTree(root->left, trunk, false);
    }
};

int main()
{
    BST bl;

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
    cout << endl
         << endl;

    // DELETE A NODE from BST TREE
    bl.Case3Deletion(bl.Root, 50);
    cout << endl;

    cout << "After Deletion Using 3rd Case (using inOrder Traverser)" << endl;
    bl.printTree(bl.Root, NULL, false);
    cout << endl;

    return 0;
}
