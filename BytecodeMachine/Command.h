#ifndef _COMMAND_H_
#define _COMMAND_H_

#include "Value.h"
#include "Stack.h"

#include <vector>
using namespace std;

typedef void (*OptionHandler) (const vector<Value>*);

struct Command
{
	const char* option;
	OptionHandler handler;
};

void cmd_Add(const vector<Value>* params);
void cmd_Sub(const vector<Value>* params);
void cmd_Mul(const vector<Value>* params);
void cmd_Div(const vector<Value>* params);
void cmd_Push(const vector<Value>* params);
void cmd_Pop(const vector<Value>* params);
void cmd_Out(const vector<Value>* params);

const Command CMD_LIST[] = {
	{ "ADD", cmd_Add },
	{ "SUB", cmd_Sub },
	{ "MUL", cmd_Mul },
	{ "DIV", cmd_Div },
	{ "PUSH", cmd_Push },
	{ "POP", cmd_Pop },
	{ "OUT", cmd_Out },
};

#endif // !_COMMAND_H_

