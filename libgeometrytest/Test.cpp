#include "Test.h"

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include "ConsoleColor.h"

ostream& operator << (ostream& s, TestResult r)
{
	switch (r)
	{
	case TestResult::Good:
		s << "Good";
		break;
	case TestResult::Bad:
		s << "Bad";
		break;
	}
	return s;
}

Test::Test(string name, function<bool()> action, bool silent)
{
	if (!silent)
	{
		cout << "[Test #" << _n << "] " << name << endl;
	}
	
	TestResult result = (TestResult)action();
	
	_names.push_back(name);
	_results.push_back(result);

	if (!silent)
	{
		cout << "[Test #" << _n << "] Result: " << result << endl;
	}

	_n++;
}


Test::~Test()
{

}

void Test::Report()
{
	CConsoleColor CC;
	cout.fill(' '); 
	cout << setiosflags(ios::left);
	for (unsigned int i = 0; i < _n; i++)
	{
		switch (_results[i])
		{
		case TestResult::Good:
			cout << color(BACKGROUND_GREEN);
			break;
		case TestResult::Bad:
			cout << color(BACKGROUND_RED);
			break;
		}
		cout << setw(3) << i;
		cout << setw(60) << _names[i];
		cout << endl;
	}
}

unsigned int Test::_n = 0;

vector<TestResult> Test::_results;

vector<string> Test::_names;
