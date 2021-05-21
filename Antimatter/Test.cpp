// Antimatter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include "byte.h"
#include "Collections.h"
#include "Console.h"
#include "Memory.h"
#include "Object.h"
#include "SigScanner.h"
#include "Strings.h"

using namespace std;

using namespace Antimatter;

#include <windows.h>
#include <stdio.h>
#include <dbghelp.h>
#pragma comment(lib, "dbghelp.lib")

HANDLE hProcess;

BOOL CALLBACK EnumSymProc(PSYMBOL_INFO pSymInfo, ULONG, PVOID userContext)
{
	size_t maxcmplen = strlen((PCHAR)userContext);
	if (maxcmplen == pSymInfo->NameLen) {
		if ((strncmp(pSymInfo->Name, (PCHAR)userContext, pSymInfo->NameLen)) == 0) {
			TI_FINDCHILDREN_PARAMS childs = {0};
			SymGetTypeInfo(hProcess, pSymInfo->ModBase, pSymInfo->TypeIndex,
			               TI_GET_CHILDRENCOUNT, &childs.Count);
			printf("%8s%10s%10s%16s %s", "Size", "TypeIndex", "Childs", "Address", "Name\n");
			printf("%8x %8x %8x %16I64x %10s\n", pSymInfo->Size, pSymInfo->TypeIndex,
			       childs.Count, pSymInfo->Address, pSymInfo->Name);
		}
	}
	return TRUE;
}

void find(const char* pdb, char* ctcx)
{
	
	DWORD64 BaseOfDll = SymLoadModuleEx(hProcess, NULL, pdb, NULL,
		0x400000, 0x20000, NULL, 0);
	SymEnumSymbols(hProcess, BaseOfDll, "*!*", EnumSymProc, ctcx);
	SymEnumTypes(hProcess, BaseOfDll, EnumSymProc, ctcx);
	SymCleanup(hProcess);
}

int main() noexcept
{
	/*_ASSERT(Contains(xstr(_MSVC_LANG),"2017"));
	_ASSERT(Is64Bit());
	SignatureScanner s{};

	auto h = s.GetProcess("ULTRAKILL.exe");
	printf("%d", h);

	auto m = s.GetModule("ULTRAKILL.exe");

	printf("%p\n", m.dwBase);
	auto sig = s.FindSignature(m.dwBase, m.dwSize, "\x02\x16\x7D\x62\x0C\x00\x04\x1F\x0C", "xxxxxxxxx");

	printf("%x\n", sig);*/
	hProcess = GetCurrentProcess();
	SymInitialize(hProcess, NULL, FALSE);
	char buf[256];
	printf("%d %s", SymGetSearchPath(GetCurrentProcess(), buf, sizeof buf),buf);
	find("C:\\Users\\Deci\\Desktop\\coreclr.pdb", (char*)"MethodDesc::Reset");


	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
