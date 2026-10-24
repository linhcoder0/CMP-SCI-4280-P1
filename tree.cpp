#include "node.h"
#include "tree.h"
#include <iostream>
#include <string>
using namespace std;

int getKey(const string& value) {
    //remove leading zeroes
    int number = stoi(value);
    return to_string(number).length();
}

Node* buildTree(Node* root, const string& value) {
    if (root == nullptr) {
        root = new Node();

        root->key = getKey(value);//creating a brand new node. example: "12" then this value is 2
        root->data.push_back(value); //add item to end of vector
        root->left = nullptr;
        root->right = nullptr;

        return root; //updates the tree for the next recursion call
    }

    int key = getKey(value); //for incoming data

    if(key < root -> key) {
        //Example: "12" has key 2 because it has 2 digits.
        //If the incoming key is less than the current node's key, it will check 
        //if the left child is a nullptr.
        //If the left child is a nullptr, a new node will be created there.
        //If the left child already has a node, we will check if the incoming key is less than or greater than
        //that node's key and move left or right respectively, until it has found a nullptr. 
        
        root->left = buildTree(root->left, value);         
        return root;
    }
    else if (key > root -> key) {
        //Example: "123" has key 3 because it has 3 digits.
        //If the incoming key is greater than the current node's key, it will check 
        //if the right child is a nullptr.
        //If the right child is a nullptr, a new node will be created there.
        //If the right child already has a node, we will check if the incoming key is less than or greater than
        //that node's key and move left or right respectively, until it has found a nullptr. 

        root->right = buildTree(root->right, value); 
        return root;
    }
    else if (key == root -> key) {
        //Example: "1" has key 1 because it has 1 digit. 
        //If the incoming key is equal to the current node's key, 
        //the incoming value ("1" not 1) belongs to that respective node's data vector, unless
        //the same datum is repeated in that data vector. 

        for (int i = 0; i < root->data.size(); i++) {
            if(root->data[i] == value) {
                return root; //same exact datum, do not add
            }
        }
        
        root -> data.push_back(value);
        return root; 
    }
    return root;
}

    void printPreorder(Node* root, ostream& output, int depth){
        if(root==nullptr) {
            return;
        }        

        for (int i = 0; i < 2 * depth; i++){
            output << " ";
        }

        output << root->key << ": ";

        for (int i = 0; i < root ->data.size(); i++){
            output << root->data[i] << " ";
        }

        output << "\n";

        printPreorder(root -> left, output, depth+1);
        printPreorder(root -> right,output, depth+1);
    }



    void printPostorder(Node* root, ostream& output, int depth){
        if(root == nullptr) {
            return;
        }

        printPostorder(root -> left, output, depth+1);
        printPostorder(root -> right,output, depth+1);

        for (int i = 0; i < 2 * depth; i++){
            output << " ";
        }

        output << root->key << ": ";

        for (int i = 0; i < root ->data.size(); i++){
            output << root->data[i] << " ";
        }

        output << "\n";
    }

