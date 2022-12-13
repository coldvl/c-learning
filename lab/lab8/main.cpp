#include <iostream>
#include "header.h"

using namespace std;

int main() {
   // Create a binary search tree.
   BST tree;

   // Insert some values into the tree.
   tree.treeHeight();
   tree.insert(5);
   tree.insert(3);
   tree.insert(7);
   tree.insert(2);
   tree.insert(4);
   tree.insert(6);
   tree.insert(8);
   tree.deleteNode(5);

   // Print the tree.
   tree.print();
   //tree.treeTraverse();
}
