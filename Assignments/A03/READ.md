## A03: BST Delete
### Eduardo Robles
### Description: 

This assignment will find a delete method to the binary search tree code.

|  #  |  File  |  Description  |
| :---: | ---------------- | -------------------------------------------------- |
|  1  |  [Link 1](A03.cpp)  |  bst.cpp has a delete method made to delete in certain cases like detailed in the instructions.  |

### Instructions:

- If it is a leaf node it can just be deleted and be made null. 
- If the parent node has one child node the delete the parent node and let the child node replace it.
- If the parent has two child nodes then let either the pre successor or the post successor take it's place.
