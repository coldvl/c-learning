#include <iostream>
using namespace std;

// define a node in the tree
struct Node {
  float data_x;
  float data_y;
  Node* left;
  Node* right;
   Node(float x, float y) : data_x(x), data_y(y), left(nullptr), right(nullptr) {}
};
 // Define a binary search tree.
class BinarySearchTree {
    private:
        Node *root;
    public:
        void insert(float x, float y);
        void print();
        void deleteNode(float x, float y);
        void deleteNodesBelowZeroByY();
        void deleteNodesBelowZeroByX();
        void preOrder();
        void print(Node *node);
        int treeHeight();
        BinarySearchTree();
        ~BinarySearchTree();
};

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
}

void BinarySearchTree::insert(float x, float y) {
    Node *node = new Node(x, y);
    if (root == nullptr) {
        root = node;
    }
    else {
        Node *current = root;
        while (true) {
            if (y < current->data_y) {
                if (current->left == nullptr) {
                    current->left = node;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == nullptr) {
                    current->right = node;
                    break;
                }
                else {
                    current = current->right;
                }
            }
        }
    }
}

void BinarySearchTree::print() {
    print(root);
}

void BinarySearchTree::print(Node *node) {
    if (node != nullptr) {
        print(node->left);
        cout << node->data_x << " " << node->data_y << endl;
        print(node->right);
    }
}

int BinarySearchTree::treeHeight() {
    Node* current = root;
    int height = 0;
    while (current != nullptr) {
        if (current->left != nullptr) {
            current = current->left;
            height++;
        }
        else if (current->right != nullptr) {
            current = current->right;
            height++;
        }
        else {
            break;
        }
    }
    cout << "Height: " << height << endl;
    return height;
}

void BinarySearchTree::deleteNode(float x, float y) {
    Node *current = root;
    Node *parent = nullptr;
    while (current != nullptr) {
        if (y < current->data_y) {
            parent = current;
            current = current->left;
        }
        else if (y > current->data_y) {
            parent = current;
            current = current->right;
        }
        else {
            if (current->left == nullptr && current->right == nullptr) {
                if (parent->left == current) {
                    parent->left = nullptr;
                }
                else {
                    parent->right = nullptr;
                }
                delete current;
            }
            else if (current->left == nullptr && current->right != nullptr) {
                if (parent->left == current) {
                    parent->left = current->right;
                }
                else {
                    parent->right = current->right;
                }
                delete current;
            }
            else if (current->left != nullptr && current->right == nullptr) {
                if (parent->left == current) {
                    parent->left = current->left;
                }
                else {
                    parent->right = current->left;
                }
                delete current;
            }
            else {
                Node *temp = current->right;
                Node *tempParent = current;
                while (temp->left != nullptr) {
                    tempParent = temp;
                    temp = temp->left;
                }
                current->data_x = temp->data_x;
                current->data_y = temp->data_y;
                if (tempParent->left == temp) {
                    tempParent->left = nullptr;
                }
                else {
                    tempParent->right = nullptr;
                }
                delete temp;
            }
            break;
        }
    }
}


void BinarySearchTree::preOrder() {
    Node* current = root;
    cout << current->data_x << " " << current->data_y << endl;
    while (current != nullptr) {
        if (current->left != nullptr) {
            current = current->left;
            cout << current->data_x << " " << current->data_y << endl;
        }
        else if (current->right != nullptr) {
            current = current->right;
            cout << current->data_x << " " << current->data_y << endl;
        }
        else {
            break;
        }
    }
}

void BinarySearchTree::deleteNodesBelowZeroByY() {
    Node* current = root;
    while (current != nullptr) {
        if (current->data_y < 0) {
            deleteNode(current->data_x, current->data_y);
        }
        if (current->left != nullptr) {
            if (current->left->data_y < 0) {
                deleteNode(current->left->data_x, current->left->data_y);
            }
            else {
                current = current->left;
            }
        }
        else if (current->right != nullptr) {
            if (current->right->data_y < 0) {
                deleteNode(current->right->data_x, current->right->data_y);
            }
            else {
                current = current->right;
            }
        }
        else {
            break;
        }
    }
}

void BinarySearchTree::deleteNodesBelowZeroByX() {
    Node* current = root;
    while (current != nullptr) {
        if (current->left != nullptr) {
            if (current->left->data_x < 0) {
                deleteNode(current->left->data_x, current->left->data_y);
            }
            else {
                current = current->left;
            }
        }
        else if (current->right != nullptr) {
            if (current->right->data_x < 0) {
                deleteNode(current->right->data_x, current->right->data_y);
            }
            else {
                current = current->right;
            }
        }
        else {
            break;
        }
    }
}

int main() {
    BinarySearchTree tree;

    tree.insert(1, -2);
    tree.insert(-2, 5);
    tree.insert(10, -4);
    tree.insert(3, 2);
    tree.insert(-4, 1);
    tree.insert(-5, -3);
    tree.insert(2, 3);
    tree.insert(4, 4);
    tree.print();
    cout << endl;
    cout << "Delete nodes below zero by Y" << endl;
    tree.deleteNodesBelowZeroByY();
    tree.print();
    cout << endl;
    cout << "Delete nodes below zero by X" << endl;
    tree.deleteNodesBelowZeroByX();
    tree.print();
    tree.treeHeight();
    tree.preOrder();
}