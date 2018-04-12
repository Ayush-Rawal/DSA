/*
 * Tree is a non-linear data stucture
 * Tree is also an ADT
*/

// Tree representation using array
/*
 * Children are assigned ids
 * ex:         1 (0)
 *       2 (1)        3 (2)
 *  4 (3)  N (4) 6 (5)  7 (6)
 * where N -> null and (index) -> index
 *  wil have representation  1 2 3 4 - 6 7
 * 
 * Formulas:
 * Parent of x (for binary) = floor(x/2) when indexing starts at 1
 *                          and floor((x + 1)/2) or floor(x/2)+1 when indexing starts at 0
 * Parent of x (for degree k) = floor(x/k) when indexing starts at 1
 *                          and floor(x/k) + 1 when indexing starts at 0
 * 
 * Possible children of x (for degree k)
 * 
 * number of children in row = k^l, where k is degree and l is height (starting from top = 0)
 * 
 * Tree Traversal
 * Inorder
 * Postorder
 * Preorder
 * 
 * 
 * Inorder: GDBEAFHC
 * Preorder: ABDGECFH
 * PostOrder: GDEBHFCA
 * 
 * When inorder and pre/postorder are given, draw tree
 * 
 * Execute preorder in the way the appear,
 * map them to inorder, those on the left/right appear on left/right side of the node 
 * 
 * ex:
 * Inorder: G D B E A F H C
 * Preorder: A B D G E C F H
 *  write A,
 * G D B E will appear on left of A,
 * while F H C will appear on right
 * recurse!
 * 
 * For postorder and inorder start from end of postorder sequence
 * 
 * No. of trees possible for nodes = (2 ^ n) - n
 */
