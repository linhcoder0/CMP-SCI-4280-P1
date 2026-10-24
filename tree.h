#ifndef TREE_H
#define TREE_H

#include "node.h"
#include <string>
#include <iostream>
using namespace std;

    Node* buildTree(Node* root, const string& value);
// Inserts one input value into the BST and returns the root of the resulting tree/subtree.
// root = current node being examined.
// value = input datum being inserted.
// The value's key is its number of digits.
// Smaller key -> go left.
// Larger key  -> go right.
// Same key    -> store the value in the current node.
// Exact same datum repeated -> should be disregarded. 
        // (12, 48, 16, 12, 19) -> 2nd 12 ignored
// If root == nullptr, create a new node there.
        //            2
        //       /      \ 
        //      1        3
        // Nodes 1 and 3 have a left == nullptr and right == nullptr

// const string& avoids copying value and prevents it from being changed.

    void printPreorder(Node* root, ostream& output, int depth);
// root = current node being visited.
// output = where the traversal should be printed.
// depth = current tree depth, used for indentation.
// Preorder order:
// current node -> left subtree -> right subtree.
// Each node is indented by (2 * depth) spaces before printing.

//                2 (12, 24)
//          /                      \ 
//      1 (1, 2, 3)        3 (583, 239, 292)
// 2 -> 1 -> 3

// 2: 12 24
//  1: 1 2 3
//  3: 583 239 292


    void printPostorder(Node* root, ostream& output, int depth);
// root = current node being visited.
// output = where the traversal should be printed.
// depth = current tree depth, used for indentation.
// Postorder order:
// left subtree -> right subtree -> current node.
// Each node is indented by (2 * depth) spaces before printing.
//                2 (12, 24)
//          /                      \ 
//      1 (1, 2, 3)        3 (583, 239, 292)
// 1 -> 3 -> 2

//  1: 1 2 3
//  3: 583 239 292
// 2: 12 24

#endif 