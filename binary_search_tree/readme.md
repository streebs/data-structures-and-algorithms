# Binary Search Tree

### Overview

This project constructs a binary search tree and implements methods for post-order and in-order tree traversal. It also implements methods to add an remove nodes into the tree. Recursion is used almost every aspect of the tree. Even the destructor uses recursion and I think that is pretty cool! :)

### Why Binary Trees?

Binary trees are really cool data structures. While not technically necassary, recursion proves quite useful in the construction and utilization of a tree. Searching a tree structure can also be more efficient that searching a list. For example a binary tree with 32 levels would have ~4.2 billion nodes! if i wanted to find a number in the binary tree, I would need to do at most 32 comparisons! Thats pretty amazing considering how many nodes there are. Trees are also quite useful for parsing programming languages as well. The construction of an abstract syntax tree\* is paramount to language parsing for compiling.

### Run This Program
This program has been compiled on a linux os for x86 architecture. The executable is located in this directory bst.exe you can run it with the following command:
```sh
./binary_search_tree/bst.exe 
```