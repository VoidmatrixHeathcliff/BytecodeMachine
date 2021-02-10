#ifndef _VALUE_H_
#define _VALUE_H_

#include <string>
using namespace std;

enum ValueType
{
	TYPE_NULL,
	TYPE_BOOLEAN,
	TYPE_NUMBER,
	TYPE_STRING,
};

struct Value
{
	ValueType type;
	string content;
};

#endif // !_VALUE_H_
