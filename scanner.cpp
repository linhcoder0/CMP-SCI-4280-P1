#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype> //isdigit
#include "token.h"
#include "scanner.h"
using namespace std;


void testScanner(istream& input) {
    Token token = scanner(input);

    while (token.type != TokenType::EOFtk) {
        cout << "Line #" << token.lineNumber << ": ";

        if (token.type == TokenType::NumberTk) {
            cout << "Number: ";
        }

        if (token.type == TokenType::OperatorTk) {
            cout << "Operator: ";
        }
        
        if (token.type == TokenType::IdentifierTk) {
            cout << "Identifier: ";
        }   

        if (token.type == TokenType::KeywordTk) {
            cout << "Keyword: ";
        }

        cout << token.instance << endl;

        token = scanner(input);
    }
}

Token scanner (istream& input){
    static int lineNumber = 1;
    int a;

    while ((a = input.get()) != EOF) {
        if (isspace(a)) {
            if (a == '\n') {
                lineNumber++;
            }
            continue;
        }

        if (a == '$') { //this is for inline comments
            int commentLine = lineNumber;
            bool closed = false;

            while ((a = input.get()) != EOF) {
                if (a == '\n') {
                    lineNumber++;
                }

                if (a == '$') {
                    closed = true;
                    break;
                }
            }

            if (!closed) {
                cerr << "LEXICAL ERROR: Unclosed comment on line "
                    << commentLine << endl;
                exit(1);
            }

            continue;
        }

        if (isalnum(a)) {//check if letter is letter or a num
            string word;
            word += char(a);

            bool hasLetter = isalpha(a);

            while(isalnum(input.peek())) {
                int next = input.get();
                word += char(next);

                if(isalpha(next)){
                    hasLetter = true;
                }
            }

            if (hasLetter) {
                if (word == "if" || 
                    word == "then" || 
                    word == "void" ||
                    word == "begin" ||
                    word == "end") {
                        return {TokenType::KeywordTk, word, lineNumber};
                    }


                return {TokenType::IdentifierTk, word, lineNumber};
            }
            return {TokenType::NumberTk, word, lineNumber};
        }

        if (a == '+') {
            return {TokenType::OperatorTk, "+", lineNumber};
        }
        if (a == '-') {
            return {TokenType::OperatorTk, "-", lineNumber};
        }
        if (a == '*') {
            return {TokenType::OperatorTk, "*", lineNumber};
        }
        if (a == '/') {
            return {TokenType::OperatorTk, "/", lineNumber};
        }
        if (a == '%') {
            return {TokenType::OperatorTk, "%", lineNumber};
        }
        if (a == '=') {
            int next = input.peek();

            if (next == '=' || next == '>' || next == '<') {
                input.get();

                string op = "=";
                op += char(next);

                return {TokenType::OperatorTk, op, lineNumber};
            }

            return {TokenType::OperatorTk, "=", lineNumber};
        }
        if (a == '<') {
            return {TokenType::OperatorTk, "<", lineNumber};
        }
        if (a == '>') {
            return {TokenType::OperatorTk, ">", lineNumber};
        }
        if (a == ':') {
            if (input.peek() == '=') {
                input.get();
                return {TokenType::OperatorTk, ":=", lineNumber};
            }

            return {TokenType::OperatorTk, ":", lineNumber};
        }
        if (a == ',') {
            return {TokenType::OperatorTk, ",", lineNumber};
        }
        if (a == ';') {
            return {TokenType::OperatorTk, ";", lineNumber};
        }
        if (a == '(') {
            return {TokenType::OperatorTk, "(", lineNumber};
        }
        if (a == ')') {
            return {TokenType::OperatorTk, ")", lineNumber};
        }
        if (a == '{') {
            return {TokenType::OperatorTk, "{", lineNumber};
        }
        if (a == '}') {
            return {TokenType::OperatorTk, "}", lineNumber};
        }
        if (a == '[') {
            return {TokenType::OperatorTk, "[", lineNumber};
        }
        if (a == ']') {
            return {TokenType::OperatorTk, "]", lineNumber};
        }
        if (a == '.') {
            return {TokenType::OperatorTk, ".", lineNumber};
        }




        cerr << "LEXICAL ERROR: Invalid character '"
            << char(a) << "' on line " << lineNumber << endl;

        exit(1);
    }

    return {TokenType::EOFtk, "", lineNumber};

}