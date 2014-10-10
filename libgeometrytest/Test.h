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
	static vector<string> _names;
	static vector<TestResult> _results;
public:
	Test(string name, function<bool()> action, bool silent = true);
	~Test();
	static void Report();
};

