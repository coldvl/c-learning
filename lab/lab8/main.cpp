#include <iostream>
#include "header.h"

using namespace std;



 int main() {
   // Create a binary search tree.
   BST tree;

   // Insert some values into the tree.
   tree.insert(5);
   tree.insert(3);
   tree.insert(7);
   tree.insert(2);
   tree.insert(4);
   tree.insert(6);
   tree.insert(8);

   // Print the tree.
   tree.print();
   cout << "Left: " << tree.get_left() << endl;
   cout << "Right: " << tree.get_right() << endl;
 }
