# 0x1D. C - Binary trees

## Description
This project focuses on the implementation of various operations and manipulations on binary trees in the C programming language. It covers the implementation of functions that cover a wide range of binary tree functionalities, including node creation, insertion, deletion, traversal, height measurement, depth calculation, size determination, leaf counting, and more. This project also extends to specialized tree types such as Binary Search Trees (BST), AVL Trees, and Max Binary Heaps, offering functions for their validation, insertion, removal, and conversion.


### File Usage
File Name | Description
--- | ---
[0-binary_tree_node.c](https://github.com/germanchuks/binary_trees/blob/master/0-binary_tree_node.c) | Function that creates a binary tree node.
[1-binary_tree_insert_left.c](https://github.com/germanchuks/binary_trees/blob/master/1-binary_tree_insert_left.c) | Function that inserts a node as the left-child of another node.
[2-binary_tree_insert_right.c](https://github.com/germanchuks/binary_trees/blob/master/2-binary_tree_insert_right.c) | Function that inserts a node as the right-child of another node. 
[3-binary_tree_delete.c](https://github.com/germanchuks/binary_trees/blob/master/3-binary_tree_delete.c) | Function that deletes an entire binary tree.
[4-binary_tree_is_leaf.c](https://github.com/germanchuks/binary_trees/blob/master/4-binary_tree_is_leaf.c) | Function that checks if a node is a leaf.
[5-binary_tree_is_root.c](https://github.com/germanchuks/binary_trees/blob/master/5-binary_tree_is_root.c) | Function that checks if a given node is a root.
[6-binary_tree_preorder.c](https://github.com/germanchuks/binary_trees/blob/master/6-binary_tree_preorder.c) | Function that goes through a binary tree using pre-order traversal.
[7-binary_tree_inorder.c](https://github.com/germanchuks/binary_trees/blob/master/7-binary_tree_inorder.c) | Function that goes through a binary tree using in-order traversal.
[8-binary_tree_postorder.c](https://github.com/germanchuks/binary_trees/blob/master/8-binary_tree_postorder.c) | Function that goes through a binary tree using post-order traversal.
[9-binary_tree_height.c](https://github.com/germanchuks/binary_trees/blob/master/9-binary_tree_height.c) | Function that measures the height of a binary tree.
[10-binary_tree_depth.c](https://github.com/germanchuks/binary_trees/blob/master/10-binary_tree_depth.c) | Function that measures the depth of a node in a binary tree.
[11-binary_tree_size.c](https://github.com/germanchuks/binary_trees/blob/master/11-binary_tree_size.c) | Function that measures the size of a binary tree.
[12-binary_tree_leaves.c](https://github.com/germanchuks/binary_trees/blob/master/12-binary_tree_leaves.c) | Function that counts the leaves in a binary tree.
[13-binary_tree_nodes.c](https://github.com/germanchuks/binary_trees/blob/master/13-binary_tree_nodes.c) | Function that counts the nodes with at least 1 child in a binary tree.
[14-binary_tree_balance.c](https://github.com/germanchuks/binary_trees/blob/master/14-binary_tree_balance.c) | Function that measures the balance factor of a binary tree. 
[15-binary_tree_is_full.c](https://github.com/germanchuks/binary_trees/blob/master/15-binary_tree_is_full.c) | Function that checks if a binary tree is full.
[16-binary_tree_is_perfect.c](https://github.com/germanchuks/binary_trees/blob/master/16-binary_tree_is_perfect.c) | Function that checks if a binary tree is perfect. 
[17-binary_tree_sibling.c](https://github.com/germanchuks/binary_trees/blob/master/17-binary_tree_sibling.c) | Function that finds the sibling of a node. 
[18-binary_tree_uncle.c](https://github.com/germanchuks/binary_trees/blob/master/18-binary_tree_uncle.c) | Function that finds the uncle of a node.
[100-binary_trees_ancestor.c](https://github.com/germanchuks/binary_trees/blob/master/100-binary_trees_ancestor.c) | Function that finds the lowest common ancestor of two nodes.
[101-binary_tree_levelorder.c](https://github.com/germanchuks/binary_trees/blob/master/101-binary_tree_levelorder.c) | Function that goes through a binary tree using level-order traversal. 
[102-binary_tree_is_complete.c](https://github.com/germanchuks/binary_trees/blob/master/102-binary_tree_is_complete.c) | Function that checks if a binary tree is complete. 
[103-binary_tree_rotate_left.c](https://github.com/germanchuks/binary_trees/blob/master/103-binary_tree_rotate_left.c) | Function that performs a left-rotation on a binary tree  
[104-binary_tree_rotate_right.c](https://github.com/germanchuks/binary_trees/blob/master/104-binary_tree_rotate_right.c) | Function that performs a right-rotation on a binary tree. 
[110-binary_tree_is_bst.c](https://github.com/germanchuks/binary_trees/blob/master/110-binary_tree_is_bst.c) | Function that checks if a binary tree is a valid Binary Search Tree.
[111-bst_insert.c](https://github.com/germanchuks/binary_trees/blob/master/111-bst_insert.c) | Function that inserts a value in a Binary Search Tree.
[112-array_to_bst.c](https://github.com/germanchuks/binary_trees/blob/master/112-array_to_bst.c) | Function that builds a Binary Search Tree from an array. 
[113-bst_search.c](https://github.com/germanchuks/binary_trees/blob/master/113-bst_search.c) | Function that searches for a value in a Binary Search Tree.
[114-bst_remove.c](https://github.com/germanchuks/binary_trees/blob/master/114-bst_remove.c) | Function that removes a node from a Binary Search Tree. 
[115-O](https://github.com/germanchuks/binary_trees/blob/master/115-O) | Contains the average time complexities of some operations on a Binary Search Tree (BST).
[120-binary_tree_is_avl.c](https://github.com/germanchuks/binary_trees/blob/master/120-binary_tree_is_avl.c) | Function that checks if a binary tree is a valid AVL Tree. 
[121-avl_insert.c](https://github.com/germanchuks/binary_trees/blob/master/121-avl_insert.c) | Function that inserts a value in an AVL Tree.
[122-array_to_avl.c](https://github.com/germanchuks/binary_trees/blob/master/122-array_to_avl.c) | Function that builds an AVL tree from an array.
[123-avl_remove.c](https://github.com/germanchuks/binary_trees/blob/master/123-avl_remove.c) | Function that removes a node from an AVL tree.
[124-sorted_array_to_avl.c](https://github.com/germanchuks/binary_trees/blob/master/124-sorted_array_to_avl.c) | Function that builds an AVL tree from an array.
[125-O](https://github.com/germanchuks/binary_trees/blob/master/125-O) | Contains the average time complexities of some operations on an AVL Tree.
[130-binary_tree_is_heap.c](https://github.com/germanchuks/binary_trees/blob/master/130-binary_tree_is_heap.c) | Function that checks if a binary tree is a valid Max Binary Heap.
[131-heap_insert.c](https://github.com/germanchuks/binary_trees/blob/master/131-heap_insert.c) | Function that inserts a value in Max Binary Heap.
[132-array_to_heap.c](https://github.com/germanchuks/binary_trees/blob/master/132-array_to_heap.c) | Function that builds a Max Binary Heap tree from an array.
[133-heap_extract.c](https://github.com/germanchuks/binary_trees/blob/master/133-heap_extract.c) | Function to extracts the root node of a Max Binary Heap.
[134-heap_to_sorted_array.c](https://github.com/germanchuks/binary_trees/blob/master/134-heap_to_sorted_array.c) | Function that converts a Binary Max Heap to a sorted array of integers.
[135-O](https://github.com/germanchuks/binary_trees/blob/master/135-O) | Contains the average time complexities of some operations on a Binary Heap.
[binary_trees.h](https://github.com/germanchuks/binary_trees/blob/master/binary_trees.h) | Header file containing prototypes of all functions used in this project, including the data structures for different binary tree types, and print function.
[binary_tree_print.c](https://github.com/germanchuks/binary_trees/blob/master/binary_tree_print.c) | Function for visualizing binary tree.

## Compilation
All files are compiled using `gcc`, using the options `-Wall -Werror -Wextra -pedantic -std=gnu89`

## Authors
* **Michael Chukwunwe** (https://github.com/stuckwithprogression)
* **German Daniel** (https://github.com/germanchuks)
