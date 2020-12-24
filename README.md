# avl_tree_insertion

* Self-balancing Binary Search Tree.  
* Difference between heights of left and right subtrees can not be more than one for all nodes.  
* Most of BST operations take O(height) time.  
* If we make sure that height of the tree remains O(Log n) after every insertion and deletion, then we can guarantee an upper bound of O(Log n) for all these operations.  

1. perform the normal Binary Search Tree.  
2. current node must be one of the ancestors of the newly inserted node.  
3. update the height of the current node.  
4. get the balance factor of the current node.  
5. left subtree height - right subtree height
6. if balance factor is greater than 1, then the current node is unbalanced and we are either in left left case or left right case.  
7. to check whether it is left left case or not, compare the newly inserted key with the key in left subtree root.  
8. if balance factor is less than -1, then the current node is unbalanced and we are either in right right case or right left case.  
9. to check whether it is right right case or not, compare the newly inserted key with key in right subtree root.