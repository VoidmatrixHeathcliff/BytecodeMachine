#ifndef _MAIN_H_
#define _MAIN_H_

#include "Value.h"
#include "Error.h"
#include "Stack.h"
#include "Command.h"

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;

#include <windows.h>

void FormatCMD(string strLine, string& option, vector<string>* params);

void HandleCMD(string option, vector<string>* params);

#endif // !_MAIN_H_

