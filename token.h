#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

enum class TokenType {
    IdentifierTk,
    NumberTk,
    OperatorTk,
    KeywordTk,
    EOFtk
};

struct Token {
    TokenType type;
    string instance;
    int lineNumber;
};

#endif