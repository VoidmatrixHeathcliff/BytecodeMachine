#include "Command.h"

void cmd_Push(const vector<Value>* params)
{
	if (params->size() != 1)
	{
		Error("执行 PUSH 指令出错：" + params->size() ? "过多的参数" : "过少的参数");
		return;
	}
	PushValue((*params)[0]);
}

void cmd_Pop(const vector<Value>* params)
{
	if (params->size())
	{
		Error("执行 POP 指令出错：过多的参数");
		return;
	}
	PopValue();
}

void cmd_Add(const vector<Value>* params)
{
	if (params->size())
	{
		Error("执行 ADD 指令出错：过多的参数");
		return;
	}
	Value* value1 = GetValue(-1);
	Value* value2 = GetValue(-2);
	if (!(value1 && value2))
	{
		Error("执行 ADD 指令出错：获取栈内参数失败");
		return;
	}
	if (!(value1->type == TYPE_NUMBER && value2->type == TYPE_NUMBER))
	{
		Error("执行 ADD 指令出错：错误的算数类型");
		return;
	}
	Value resultValue = { TYPE_NUMBER, to_string(atof(value1->content.c_str()) + atof(value2->content.c_str())) };
	PopValue();
	PopValue();
	PushValue(resultValue);
}

void cmd_Sub(const vector<Value>* params)
{
	if (params->size())
	{
		Error("执行 SUB 指令出错：过多的参数");
		return;
	}
	Value* value1 = GetValue(-1);
	Value* value2 = GetValue(-2);
	if (!(value1 && value2))
	{
		Error("执行 SUB 指令出错：获取栈内参数失败");
		return;
	}
	if (!(value1->type == TYPE_NUMBER && value2->type == TYPE_NUMBER))
	{
		Error("执行 SUB 指令出错：错误的算数类型");
		return;
	}
	Value resultValue = { TYPE_NUMBER, to_string(atof(value2->content.c_str()) - atof(value1->content.c_str())) };
	PopValue();
	PopValue();
	PushValue(resultValue);
}

void cmd_Mul(const vector<Value>* params)
{
	if (params->size())
	{
		Error("执行 MUL 指令出错：过多的参数");
		return;
	}
	Value* value1 = GetValue(-1);
	Value* value2 = GetValue(-2);
	if (!(value1 && value2))
	{
		Error("执行 MUL 指令出错：获取栈内参数失败");
		return;
	}
	if (!(value1->type == TYPE_NUMBER && value2->type == TYPE_NUMBER))
	{
		Error("执行 MUL 指令出错：错误的算数类型");
		return;
	}
	Value resultValue = { TYPE_NUMBER, to_string(atof(value1->content.c_str()) * atof(value2->content.c_str())) };
	PopValue();
	PopValue();
	PushValue(resultValue);
}

void cmd_Div(const vector<Value>* params)
{
	if (params->size())
	{
		Error("执行 DIV 指令出错：过多的参数");
		return;
	}
	Value* value1 = GetValue(-1);
	Value* value2 = GetValue(-2);
	if (!(value1 && value2))
	{
		Error("执行 DIV 指令出错：获取栈内参数失败");
		return;
	}
	if (!(value1->type == TYPE_NUMBER && value2->type == TYPE_NUMBER))
	{
		Error("执行 DIV 指令出错：错误的算数类型");
		return;
	}
	if (!atof(value1->content.c_str()))
	{
		Error("执行 DIV 指令出错：除数为0");
		return;
	}
	Value resultValue = { TYPE_NUMBER, to_string(atof(value2->content.c_str()) / atof(value1->content.c_str())) };
	PopValue();
	PopValue();
	PushValue(resultValue);
}

void cmd_Out(const vector<Value>* params)
{
	if (params->size())
	{
		Error("执行 OUT 指令出错：过多的参数");
		return;
	}
	Value* value = GetValue(-1);
	if (!value)
	{
		Error("执行 OUT 指令出错：获取栈内参数失败");
		return;
	}
	cout << value->content << endl;
}
