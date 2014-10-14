#pragma once

#include <vector>
#include <string>
#include <functional>

using namespace std;

enum class TestResult : bool
{
	Good = true,
	Bad = false
};

class Test
{
	static unsigned int _n;
	struct Info
	{
		string name;
		TestResult result;
		string message;
	};
	static vector<Info> _infos;

	static bool test_running;
public:
	Test(string name, function<bool()> action);
	~Test();
	static void Report();
	static string LastMessage;
	static bool Silent;
	static bool PauseAfterTest;
#define TestAssert(expression) \
	if ((expression) != true) \
	{ \
	Test::LastMessage.clear(); \
	Test::LastMessage += "Failed assertion "; \
	Test::LastMessage += #expression; \
	return false; \
	}
};

