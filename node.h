#ifndef NODE_H
#define NODE_H

#include <string>
#include <vector>
using namespace std;

struct Node {
    int key; //represents the length count that this respective node represents
    //i.e. "123" = key 3 
    vector <string> data;
    //the values stored in that node
    //the reason why this is a string instead of int is because
    //"Visiting a node will print starting with indentation of 2x depth 
    //(root is at depth 0) then the node's key followed by the character ':' 
    //and WS followed by the list of strings from the node separated by 
    //WS (retaining the original ordering as according to 
    //appearance in the input file)."
    //so this is just preserving their original text and input order
    Node* left;
    //points to left node
    Node* right;
    //points to right node

};


#endif
