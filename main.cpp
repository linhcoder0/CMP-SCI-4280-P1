#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void testScanner();

int main(int argc, char* argv[]) {
        if(argc == 1) { //stdin

        }

        else if (argc == 2) { // ./P1 (filename)
            string filename = string(argv[1]) + ".fs26s2"; // ./P1 (filename)
            ifstream file(filename);

            if(!file.is_open()) {
                cerr << "LEXICAL ERROR: File cannot be opened." << endl;
                return 1;
            }

            char c;
            while(file.get(c)) {
                cout << c; 
            }

            file.close();
        }

        else {
            cerr << "LEXICAL ERROR: Invalid number of arguments." << endl;
            return 1;
        }

        return 0;
}