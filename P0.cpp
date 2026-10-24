#include "tree.h"
#include <iostream>
#include <string>
#include <fstream>
#include <cctype>
using namespace std;

    bool isValidNumber(const string& s) {
        for (int i = 0; i < s.length(); i++) {
            if (!isdigit(s[i])) {
                return false;
            }
        }

        return true;
    }

int main (int argc, char* argv[]) {
    //./P0 = 1 arg
    Node* root = nullptr; //empty tree
    string outputName;

    if (argc == 1) { 
            outputName = "out"; //./P0 = outputName = out = out.preorder / out.postorder

            string content;
            while (cin >> content) {
                if(!isValidNumber(content)) {
                    cout << "Warning: invalid datum " << content << " was skipped\n";
                    continue; 
                    //if a datum contains anything but digits, 
                    //a warning message should be issued to 
                    //one per line for each bad datum, and the datum is skipped.
                }

                root = buildTree(root, content);
            }
    }

    //User types: ./P0
    //User types: ./P0 < somefile.txt
        //If somefile.txt does exist, argc is still 1 because Bash handles the input redirection.

    else if (argc == 2) {
        outputName = argv[1]; //./P0 somefile = outputName = somefile = somefile.preorder / somefile.postorder
        string filename = string(argv[1]) + ".fs26s2";
        ifstream file(filename);
        string content;

        if (!file) {
            cerr << "Error: Could not open " << filename << "\n";
            return 1;
        }
            while(file >> content) {
                    if(!isValidNumber(content)) {
                    cout << "Warning: invalid datum " << content << " was skipped\n";
                    continue; 
                    //if a datum contains anything but digits, 
                    //a warning message should be issued to stdout, 
                    //one per line for each bad datum, and the datum is skipped.
                }
                root = buildTree(root, content);
            }
            
    } 

    //User types: ./P0 somefile.txt
    else {
        cerr << "Error: Invalid number of arguments.\n";
        return 1;
    }

    ofstream preorderFile(outputName + ".preorder");
    ofstream postorderFile(outputName + ".postorder");

    if (!preorderFile || !postorderFile) {
    cerr << "Error: Could not create output files.\n";
    return 1;
    }

    printPreorder(root, preorderFile, 0);
    printPostorder(root, postorderFile, 0);

    return 0; 
}