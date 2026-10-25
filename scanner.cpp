#include <iostream>
#include <fstream>
#include <string>
using namespace std;


void testScanner(istream& input) {
    int lineNumber = 1;
    char a;
    string number;
    
    while (input.get(a)) {
        if(a == '\n') {
            if(!number.empty()){
                cout << "Number: " << number << endl;
                number.clear();
            }

            lineNumber++;
            continue;
        }

        if(a == ' ') {
            if(!number.empty()){
                cout << "Number: " << number << endl;
                number.clear();
            }
            // cout << "Line #" << lineNumber << ": You entered: [SPACE]" << a << endl;
        }

        // if(a == '+') {
        //     if(!number.empty()){
        //     cout << "Number: " << number << endl;
        //     number.clear();
        //     }
        // }

        if(isdigit(a)){
        number += a;
        // } else { //123+/a/b/x/$/@
        //         if(!number.empty()){
        //         cout << "Operator: " << number << endl;
        //         number.clear();
        //     }
        // }

        cout << "Line #" << lineNumber << ": You entered: " << a << endl;
    } 

        if(!number.empty()){
            cout << "Number: " << number << endl;
            number.clear();
        } //prints remaining number when reaches EOF in case final line doesn't end with \n. 

}
