/* 
Name: Nur 'Aleya Addina Binti Mohd Wahid
Student ID: 22010282
Lab Group: G1
Lab: Lab 8 (Binary Search Tree)  
*/

#include <iostream>
using namespace std;

class Node
{
public:
    string name;
    Node *left;
    Node *right;

    Node(const string& n) : name(n), left(nullptr), right(nullptr) {}
};

class BinarySearchTree
{
private:
    Node *root;

    void insert_recursive(Node *&current, const string& name)
    {
        if (!current)
        {
            current = new Node(name);
            return;
        }

        if (name < current->name)
        {
            insert_recursive(current->left, name);
        }
        else if (name > current->name)
        {
            insert_recursive(current->right, name);
        }
        else
        {
            cout << "Duplicate entry \"" << name << "\" not allowed." << endl;
        }
    }

    void inorder_display(Node *node) const
    {
        if (!node)
            return;
        inorder_display(node->left);
        cout << " " << node->name;
        inorder_display(node->right);
    }

    void delete_tree(Node *node)
    {
        if (!node)
            return;
        delete_tree(node->left);
        delete_tree(node->right);
        delete node;
    }

public:
    BinarySearchTree() : root(nullptr) {}

    ~BinarySearchTree()
    {
        delete_tree(root);
    }

    void insert(const string& name)
    {
        insert_recursive(root, name);
    }

    void display_inorder() const
    {
        cout << "In-order Traversal:";
        inorder_display(root);
        cout << endl;
    }
};

int main()
{
    BinarySearchTree bst;

    // Insert nodes in a way that maintains BST property
    string names[] = {"E", "B", "G", "A", "D", "F", "C"};
    for (const string& name : names)
    {
        bst.insert(name);
    }

    bst.display_inorder();

    return 0;
}

