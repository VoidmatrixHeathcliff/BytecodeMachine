#include "Stack.h"

Value* GetValue(int index)
{
	int validIndex = index >= 0 ? index : _stack.size() + index;

	if (validIndex >= 0 && validIndex < _stack.size())
		return &_stack[validIndex];

	Error("尝试获取栈索引："+ to_string(index) + " 时出错");
	return nullptr;
}

int PushValue(Value value)
{
	_stack.push_back(value);
	return _stack.size() - 1;
}

int PopValue()
{
	_stack.size() > 0 ? _stack.pop_back() : Error("尝试弹出栈顶元素时出错");

	return _stack.size() - 1;
}