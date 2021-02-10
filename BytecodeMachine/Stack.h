#ifndef _STACK_H_
#define _STACK_H_

#include "Error.h"
#include "Value.h"

#include <vector>
using namespace std;

extern vector<Value> _stack;

Value* GetValue(int index);

int PushValue(Value value);

int PopValue();

#endif // !_STACK_H_

