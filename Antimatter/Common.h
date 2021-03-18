// ReSharper disable CppInconsistentNaming
// ReSharper disable CppClangTidyCppcoreguidelinesMacroUsage
// ReSharper disable once CppUnusedIncludeDirective

#pragma once



#include <sal.h>

/*
 * 64-bit long
 */
typedef long long llong;

/*
 * C String
 */
typedef const char* CString;

#define xstr(s) str(s)
#define str(s) #s
#define glue(a,b) a##b

#define FORMAT_STR __format_string

#define QuickFormat(id,fmt, ...) \
	char id[128]; \
	sprintf(buf, fmt, __VA_ARGS__)

template <typename T, size_t N>
constexpr size_t ArraySize(const T(&)[N]) { return N; }