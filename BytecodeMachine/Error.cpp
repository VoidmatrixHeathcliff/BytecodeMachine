#include "Error.h"

void Error(string info)
{
	cout << "[Error：" << indexLine << "] " << info << endl;

	HasError = true;
}