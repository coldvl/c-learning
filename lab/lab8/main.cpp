#include <iostream>
using namespace std;

// define a node in the tree
struct Node {
  float data_x;
  float data_y;
  Node* left;
  Node* right;
  Node* parent;
   Node(float x, float y) : data_x(x), data_y(y), left(nullptr), right(nullptr) {}
};
 
 //create a function to print the tree using template
template <typename T>
void printTree(Node* node, T outputF) {
  if (node == nullptr) {
    return;
  }
  printTree(node->left, outputF);
  outputF(node);
  printTree(node->right, outputF);
}
 
 // Define a binary search tree.

class BinarySearchTree {
    private:
        Node *root;
        int nodesQuantity;
        int height =1;
    public:
        void insert(float x, float y);
        void print();
        void deleteNode(float x, float y);
        void deleteNodesBelowZeroByY();
        void deleteNodesBelowZeroByY(Node *node);
        void deleteNodesBelowZeroByX();
        void print(Node *node);
        void printYaboveZero();
        void printYaboveZero(Node *node);;
        int treeHeight();
        void treeHeight(Node *node);
        void switchToRight(Node *node);
        void switchToLeft(Node *node);
        Node* getRoot();
        BinarySearchTree();
        ~BinarySearchTree();
};

BinarySearchTree::BinarySearchTree() {
    root = nullptr;
}

BinarySearchTree::~BinarySearchTree() {
    delete root;
}

Node* BinarySearchTree::getRoot() {
    return root;
}

void BinarySearchTree::insert(float x, float y) {
    Node *newNode = new Node(x, y);
    if (root == nullptr) {
        root = newNode;
    }
    else {
        Node *current = root;
        while (current != nullptr) {
            if (y < current->data_y) {
                if (current->left == nullptr) {
                    current->left = newNode;
                    newNode->parent = current;
                    break;
                }
                else {
                    current = current->left;
                }
            }
            else if (y > current->data_y) {
                if (current->right == nullptr) {
                    current->right = newNode;
                    newNode->parent = current;
                    break;
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
}

void BinarySearchTree::print() {
    nodesQuantity = 0;
    print(root);
    cout << "Nodes quantity: " << nodesQuantity << endl;
}

void BinarySearchTree::print(Node *node) {
    if (node != nullptr) {
        print(node->left);
        cout << node->data_x << " " << node->data_y << endl;
        nodesQuantity++;
        print(node->right);
    }
}




void BinarySearchTree::printYaboveZero() {
    printYaboveZero(root);
}

void BinarySearchTree::printYaboveZero(Node *node) {
    if (node != nullptr) {
        printYaboveZero(node->left);
        if (node->data_y > 0) {
            cout << node->data_x << " " << node->data_y << endl;
        }
        printYaboveZero(node->right);
    }
}

void BinarySearchTree::switchToLeft(Node *node) {
    if (node->left != nullptr) {
        node = node->left;
        cout << node->data_x << " " << node->data_y << endl;
    }
}

void BinarySearchTree::switchToRight(Node *node) {
    if (node->right != nullptr) {
        node = node->right;
        cout << node->data_x << " " << node->data_y << endl;
    }
}

int BinarySearchTree::treeHeight() {
    Node* current = root;
        switchToLeft(current);
        for (int i = 0; i < height; i++) {
            current = current->parent;
        }
        
        switchToRight(current);   
    
    
    
    return height;

}

void BinarySearchTree::treeHeight(Node *node) {
    if (node->left != nullptr) {
        node = node->left;
        height++;
        treeHeight(node);
    }
    else if (node->right != nullptr) {
        node = node->right;
        height++;
        treeHeight(node);
    }
    else {
        return;
    }
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

void BinarySearchTree::deleteNodesBelowZeroByY() {
    deleteNodesBelowZeroByY(root);
}

/*void BinarySearchTree::deleteNodesBelowZeroByY(Node* node) {
    if (node != nullptr) {
        deleteNodesBelowZeroByY(node->left);
        if (node->data_y < 0) {
            deleteNode(node->data_x, node->data_y);
        }
    }
}*/

void BinarySearchTree::deleteNodesBelowZeroByY(Node* current) {
    while (current != nullptr) {
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

    tree.insert(1, 0);
    tree.insert(-2, 5);
    tree.insert(10, -4);
    tree.insert(3, 2);
    tree.insert(-5, 10);
    tree.insert(-5, -3);
    tree.insert(2, 3);
    tree.insert(4, 4);
    tree.print();
    cout << endl;
    cout << "Print tree using template" << endl;
    printTree(tree.getRoot(), [](Node* node) { cout << node->data_x << " " << node->data_y << endl; });
    cout << endl;
    //tree.treeHeight();
    cout << endl;
    cout << "Delete nodes below zero by Y" << endl;
    tree.deleteNodesBelowZeroByY();
    tree.print();
    cout << endl;
    cout << "Delete nodes below zero by X" << endl;
    tree.deleteNodesBelowZeroByX();
    tree.print();
    cout << endl;
    //cout << "Tree height" << endl;
    //cout << tree.treeHeight();
    cout << endl;
    cout << endl;
    cout << "Print nodes with Y above zero" << endl;
    tree.printYaboveZero();

    return 0;
}