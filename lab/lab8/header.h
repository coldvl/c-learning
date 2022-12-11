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
        // Constructor.
        BST() : root_(nullptr) {}
        // Insert a new node into the tree.
        void insert(int data);
        // Print the tree.
        void print() {
        print(root_);
        }
        int get_left() {
            return count_left;
        }
        int get_right() {
            return count_right;
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
    
    cout << node->data << endl;
     // Print the right subtree.
    //cout << "\t";
    print(node->right);
  }
        // The root of the tree.
        Node* root_;
        int count_left = 0;
    int count_right = 0;
};

void BST::insert(int data) {
    // If the tree is empty, create a new node as the root.
    if (root_ == nullptr) {
      root_ = new Node(data);
      count_left = 1;
      count_right = 1;
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
               count_left++;
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
               count_right++;
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
