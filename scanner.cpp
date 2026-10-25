#include <iostream>
#include <fstream>
#include <string>
#include <cctype> //isdigit
using namespace std;


void testScanner(istream& input) {
    int lineNumber = 1;
    char a;
    string number;
    string letter;

    while (input.get(a)) {
        if(a == '\n') {
            if(!number.empty()){
                    cout << "Line #" << lineNumber << ": Number: " << number << endl;
                number.clear();
            }

            if(!letter.empty()){
                    cout << "Line #" << lineNumber << ": Letter: " << letter << endl;
                letter.clear();
            }


            lineNumber++;
            continue;
        }

        if(a == ' ') {
            if(!number.empty()){
                    cout << "Line #" << lineNumber << ": Number: " << number << endl;
                number.clear();
            }

            if(!letter.empty()){
                    cout << "Line #" << lineNumber << ": Letter: " << letter << endl;
                letter.clear();
            }
            // cout << "Line #" << lineNumber << ": You entered: [SPACE]" << a << endl;
        }
        
        if(isdigit(a)){
            number += a;
        } else { //123+/a/b/x/$/@
                if(!number.empty()){
                    cout << "Line #" << lineNumber << ": Number: " << number << endl;
                    number.clear();
                }
        }

        if(isalpha(a)){
            letter += a;
        } else { 
                if(!letter.empty()){
                    cout << "Line #" << lineNumber << ": Letter: " << letter << endl;
                    letter.clear();
                }
                // if(a == '+') {
                //     cout << "Operator: +" << endl;
                // }
                // if(a == '-') {
                //     cout << "Operator: -" << endl;
                // }
                // if(a == '*') {
                //     cout << "Operator: *" << endl;
                // }
                // if(a == '/') {
                //     cout << "Operator: /" << endl;
                // }
        }


        // cout << "Line #" << lineNumber << ": You entered: " << a << endl;
                if(a == '+') {
                    cout << "Line #" << lineNumber << ": Operator: +" << endl;
                }
                if(a == '-') {
                    cout << "Line #" << lineNumber << ": Operator: -" << endl;
                }
                if(a == '*') {
                    cout << "Line #" << lineNumber << ": Operator: *" << endl;
                }
                if(a == '/') {
                    cout << "Line #" << lineNumber << ": Operator: /" << endl;
                }
    }    

        if(!number.empty()){
            cout << "Line #" << lineNumber << ": Number: " << number << endl;
            number.clear();
        } //prints remaining number when reaches EOF in case final line doesn't end with \n. 

        if(!letter.empty()){
            cout << "Line #" << lineNumber << ": Letter: " << letter << endl;
            letter.clear();
        }
}
