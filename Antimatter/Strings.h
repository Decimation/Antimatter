#pragma once
#include <string>
#include <Windows.h>
#include <comdef.h>

inline char* wchar_to_char(WCHAR* w)
{
	_bstr_t b(w);
	return b;
}

inline bool Contains(const std::string& s, const std::string& b)
{
	return s.find(b) != std::string::npos;
}
