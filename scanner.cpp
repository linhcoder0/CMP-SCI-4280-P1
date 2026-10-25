#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void testScanner(istream& input) {
    char a;

    while (input.get(a)) {
        cout << "You entered: " << a << endl;
    } 

}

