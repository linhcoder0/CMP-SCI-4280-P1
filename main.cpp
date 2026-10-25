#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void testScanner();

int main(int argc, char* argv[]) {

        ifstream file("somefile.fs26s2");

        if(!file.is_open()) {
            cerr << "LEXICAL ERROR: File cannot be opened." << endl;
            return 1;
        }

        // string s;

        // while(getline(file, s)) {
        //     cout << s << endl;
        // }

        char c;
        while(file.get(c)) {
            cout << c; 
        }

        file.close();

        return 0;
}