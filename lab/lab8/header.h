#include <iostream>

using namespace std;

// define a node in the tree
struct Node {
  int data;
  Node* left;
  Node* right;
   Node(int d) : data(d), left(nullptr), right(nullptr) {}
};
 // Define a binary search tree.
class BST {
    public:
        int height = 0;
        int j=0;
        // Constructor.
        BST() : root_(nullptr) {}
        // Insert a new node into the tree.
        void insert(int data);
        // Print the tree.
        void print() {
        print(root_);
        }
        int treeHeight() {
            Node* current = root_;
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

        void deleteNode(int data) {
            Node* current = root_;
            Node* parent = nullptr;
            while (current != nullptr) {
                if (data < current->data) {
                    parent = current;
                    current = current->left;
                }
                else if (data > current->data) {
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
                        break;
                    }
                    else if (current->left == nullptr) {
                        if (parent->left == current) {
                            parent->left = current->right;
                        }
                        else {
                            parent->right = current->right;
                        }
                        delete current;
                        break;
                    }
                    else if (current->right == nullptr) {
                        if (parent->left == current) {
                            parent->left = current->left;
                        }
                        else {
                            parent->right = current->left;
                        }
                        delete current;
                        break;
                    }
                    else {
                        Node* temp = current->right;
                        Node* tempParent = current;
                        while (temp->left != nullptr) {
                            tempParent = temp;
                            temp = temp->left;
                        }
                        if (tempParent->left == temp) {
                            tempParent->left = temp->right;
                        }
                        else {
                            tempParent->right = temp->right;
                        }
                        current->data = temp->data;
                        delete temp;
                        break;
                    }
                }
            }
        }
    private:
        // Print the tree starting at the given node.
        void print(Node* node) {
    if (node == nullptr) {
      return;
    }
     // Print the left subtree.
    //cout << "\t";
    print(node->left);
     // Print the current node.
    for (int i=height-j; i>0; i--)
        cout << "\t";
    j++;
    cout << node->data << endl;
    
     // Print the right subtree.
    //cout << "\t";
    print(node->right);
  }
        // The root of the tree.
        Node* root_;
};

void BST::insert(int data) {
    // If the tree is empty, create a new node as the root.
    if (root_ == nullptr) {
      root_ = new Node(data);
    }
    else {
      // Start at the root of the tree.
      Node* current = root_;
       // Loop until we find the correct location to insert the new node.
      while (true) {
        // If the new data is less than the current node's data, go left.
        if (data < current->data) {
           
          // If there is no left child, insert the new node here.
          if (current->left == nullptr) {
            current->left = new Node(data);
            if (current->right == nullptr) {
           }
               
            break;
          }
          else {
            // Move to the left child.
            current = current->left;
          }
        }
        else {
          // If the new data is greater than or equal to the current node's data, go right.
           //If there is no right child, insert the new node here.
           
          if (current->right == nullptr) {
               current->right = new Node(data);
               if (current->left == nullptr) {
               }
            break;
          }
          else {
            // Move to the right child.
            current = current->right;
          }
        }
      }
    }
  }
