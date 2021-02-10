#include "Main.h"

int indexLine = 1;

bool HasError = false;

vector<Value> _stack;

int main(int argc, char** argv)
{
	SetConsoleOutputCP(65001);

	string strLine;
	if (argc > 1)
	{
		ifstream inputFile(argv[1]);
		while (getline(inputFile, strLine))
		{
			if (!strLine.empty() && strLine[0] != ';')
			{
				string option;
				vector<string> params;
				FormatCMD(strLine, option, &params);
				HandleCMD(option, &params);
			}

			if (HasError)
				break;

			indexLine++;
		}
	}
	else
	{
		while (!HasError)
		{
			cout << ">> ";
			getline(cin, strLine);
			if (!strLine.empty() && strLine[0] != ';')
			{
				string option;
				vector<string> params;
				FormatCMD(strLine, option, &params);
				HandleCMD(option, &params);
			}

			indexLine++;
		}
	}

	return 0;
}

void FormatCMD(string strLine, string& option, vector<string>* params)
{
	string raw_params;
	if (strLine.find_first_of(' ') == string::npos)
	{
		option = strLine;
	}
	else
	{
		option = strLine.substr(0, strLine.find_first_of(' '));
		raw_params = strLine.substr(strLine.find_first_of(' '));
	}

	if (!raw_params.empty())
	{
		string::size_type pos1 = 0, pos2 = raw_params.find(',');
		while (string::npos != pos2)
		{
			string temp = raw_params.substr(pos1, pos2 - pos1);
			temp.erase(0, temp.find_first_not_of(" "));
			if (!temp.empty())
				params->push_back(temp);

			pos1 = pos2 + 1;
			pos2 = raw_params.find(',', pos1);
		}
		if (pos1 != raw_params.length())
		{
			string temp = raw_params.substr(pos1);
			temp.erase(0, temp.find_first_not_of(" "));
			if (!temp.empty())
				params->push_back(temp);
		}
	}
}

void HandleCMD(string option, vector<string>* params)
{
	OptionHandler handler = nullptr;
	for (auto cmd : CMD_LIST)
	{
		if (cmd.option == option)
		{
			handler = cmd.handler;
			break;
		}
	}
	if (handler)
	{
		vector<Value> values;
		for (auto param : *params)
		{
			Value value;

			if (param[0] == '\"' && param[param.size() - 1] == '\"')
			{
				value = { TYPE_STRING, param.substr(1, param.size() - 2) };
			}
			else if (param == "true" || param == "false" || param == "null")
			{
				value = { param == "null" ? TYPE_NULL : TYPE_BOOLEAN, param };
			}
			else
			{
				bool isAllNumber = true;
				for (size_t i = 0; i < param.size(); i++)
				{
					if (i == 0 && (param[i] == '+' || param[i] == '-'))
					{
						continue;
					}
					if (!(param[i] >= '0' && param[i] <= '9'))
					{
						isAllNumber = false;
						break;
					}
				}
				if (isAllNumber)
					value = { TYPE_NUMBER, param };
				else
				{
					Error("未知类型值：" + param);
					return;
				}
			}

			values.push_back(value);
		}
		handler(&values);
	}
	else
		Error("未知指令：" + option);
}