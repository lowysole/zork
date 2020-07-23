#include "utils.h"

bool compareChar(const char& c1, const char& c2)
{
	if (c1 == c2)
		return true;
	else if (toupper(c1) == toupper(c2))
		return true;
	return false;
}

bool Compare(const string& str1, const string& str2)
{
	return ((str1.size() == str2.size()) &&
		std::equal(str1.begin(), str1.end(), str2.begin(), &compareChar));
}

void ParseInput(const string& line, vector<string>& arguments)
{
	const char* str = line.c_str();

	do
	{
		const char *begin = str;

		while (*str != ' ' && *str)
			str++;

		arguments.push_back(string(begin, str));
	} while (0 != *str++);
}