#include <iostream>

using namespace std;

class Node {
    int x;
    Node * root;
    Node * left, * right;
    Node(int key);
    ~Node();
    bool exists(Node * root, int val);
    Node * insert(Node * root, int val);
    int depth(Node * root);
    void print(Node * root);
    
};

Node::Node(int key)
{
    x = key; //1
        left = nullptr;
        right = nullptr;
}

Node::~Node() 
{
        if (left)
            delete left;
        if (right)
            delete right;
}

bool Node::exists(Node * root, int val) 
{
    if (root == nullptr)
        return false;
    if (root->x == val)
        return true;
    if (val < root->x)
        return exists(root->left, val);
    return exists(root->right, val);
}

Node *Node::insert(Node * root, int val) 
{
    if (exists(root, val))
        return root;
    if (root==nullptr)
        return new Node(val);
    if (val < root->x)
        root->left = insert(root->left, val);
    if (val > root->x)
        root->right = insert(root->right, val);
    return root;
}

int Node::depth (Node * root) 
{
    if (root == nullptr)
        return 0;
    return max(depth(root->right), depth(root->left)) + 1;
}

void Node::print(Node * root) 
{
    if (root == nullptr)
        return;
    if (root->left == nullptr && root->right == nullptr) {
        cout << root-> x << endl;
    } else {
        print(root->left);
        print(root->right);
    }
}