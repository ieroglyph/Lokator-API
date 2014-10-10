// ConsoleColor.h

#pragma once
#include <iostream>
#include <windows.h>

enum color
{
	red = FOREGROUND_RED | FOREGROUND_INTENSITY,
	green = FOREGROUND_GREEN | FOREGROUND_INTENSITY,
	blue = FOREGROUND_BLUE | FOREGROUND_INTENSITY,
	yellow = FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY,
	white = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE
};

inline std::ostream& operator<< (std::ostream& s, const color& c)
{
	HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdout, c);
	return s;
}

class CConsoleColor
{
public:
	CConsoleColor()
	{
		mHstdOut = GetStdHandle(STD_OUTPUT_HANDLE);
		GetConsoleScreenBufferInfo(mHstdOut, &mCsbi);
	}

	~CConsoleColor()
	{
		SetConsoleTextAttribute(mHstdOut, mCsbi.wAttributes);
	}

private:
	HANDLE mHstdOut;
	CONSOLE_SCREEN_BUFFER_INFO mCsbi;
};

