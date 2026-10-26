#ifndef SCANNER_H
#define SCANNER_H

#include <iostream>
#include "token.h"
using namespace std;

void testScanner(istream& input);
Token scanner(istream& input);

#endif