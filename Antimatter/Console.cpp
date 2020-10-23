// ReSharper disable CppClangTidyClangDiagnosticFormatNonliteral
#include "Console.h"

#include <cstdarg>
#include <iostream>


namespace Antimatter
{
	void Console::Write(FORMAT_STR CString s, ...)
	{
		std::va_list args;
		va_start(args, s);
		vprintf(s, args);
		va_end(args);
	}
}
