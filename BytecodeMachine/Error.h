#ifndef _ERROR_H_
#define _ERROR_H_

#include "Value.h"

#include <iostream>
using namespace std;

extern bool HasError;

extern int indexLine;

void Error(string info);

#endif // !_ERROR_H_
