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

Test::Test(string name, function<bool()> action)
{
	TestResult result = TestResult::Good;

	LastMessage = "Nothing interesting happened";

	try
	{
		result = (TestResult)action();
	}
	catch (...)
	{
		LastMessage = "Uncaught exception!!!";
	}


	if (!Silent)
	{
		CConsoleColor CC;
		cout.fill(' ');
		cout << setiosflags(ios::left);

		switch (result)
		{
		case TestResult::Good:
			cout << color(BACKGROUND_GREEN);
			break;
		case TestResult::Bad:
			cout << color(BACKGROUND_RED);
			break;
		}

		cout << setw(3) << _n;
		cout << setw(45) << name;
		cout << setw(30) << LastMessage;
		cout << endl;

	}

	_infos.push_back({ name, result, LastMessage });

	_n++;

	if (PauseAfterTest)
	{
		system("pause");
	}
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
		switch (_infos[i].result)
		{
		case TestResult::Good:
			cout << color(BACKGROUND_GREEN);
			break;
		case TestResult::Bad:
			cout << color(BACKGROUND_RED);
			break;
		}
		cout << setw(3) << i;
		cout << setw(45) << _infos[i].name;
		cout << setw(30) << _infos[i].message;
		cout << endl;
	}
}

bool Test::PauseAfterTest = false;

bool Test::Silent = true;

std::string Test::LastMessage = "No tests, huh?";

bool Test::test_running = false;

unsigned int Test::_n = 0;

vector<Test::Info> Test::_infos;

