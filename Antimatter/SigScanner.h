#pragma once

#include <iostream>
#include <string>

#include <Windows.h>
#include <TlHelp32.h>

#include "Common.h"
#include "Strings.h"


// Better than using namespace std;

using std::cout;
using std::endl;
using std::string;

// datatype for a module in memory (dll, regular exe) 
struct Module
{
	DWORD dwBase, dwSize;
};

class SigScanner
{
public:
	Module TargetModule; // Hold target module
	HANDLE TargetProcess; // for target process
	DWORD TargetId; // for target process

	// For getting a handle to a process
	HANDLE GetProcess(const char* processName)
	{
		HANDLE handle = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
		PROCESSENTRY32 entry{};
		entry.dwSize = sizeof(entry);

		do
			if (!strcmp(wchar_to_char(entry.szExeFile), processName)) {
				TargetId = entry.th32ProcessID;
				CloseHandle(handle);
				TargetProcess = OpenProcess(PROCESS_ALL_ACCESS, false, TargetId);
				return TargetProcess;
			}
		while (Process32Next(handle, &entry));

		return nullptr;
	}

	// For getting information about the executing module
	Module GetModule(const char* moduleName)
	{
		HANDLE hmodule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE, TargetId);
		MODULEENTRY32 mEntry{};
		mEntry.dwSize = sizeof(mEntry);

		do {
			if (!strcmp(wchar_to_char(mEntry.szModule), moduleName)) {
				CloseHandle(hmodule);

				TargetModule = {reinterpret_cast<DWORD>(mEntry.hModule), mEntry.modBaseSize};
				return TargetModule;
			}
		}
		while (Module32Next(hmodule, &mEntry));

		const Module mod = {static_cast<DWORD>(false), static_cast<DWORD>(false)};
		return mod;
	}

	// Basic WPM wrapper, easier to use.
	template <typename T>
	bool WriteMemory(void* address, T value)
	{
		return WriteProcessMemory(TargetProcess, address, &value, sizeof(T), nullptr);
	}

	// Basic RPM wrapper, easier to use.
	template <typename T>
	T ReadMemory(void* address)
	{
		T value{};
		ReadProcessMemory(TargetProcess, address, &value, sizeof(T), nullptr);
		return value;
	}

	// for comparing a region in memory, needed in finding a signature
	static bool MemoryCompare(const BYTE* bData, const BYTE* bMask, const char* szMask)
	{
		for (; *szMask; ++szMask, ++bData, ++bMask) {
			if (*szMask == 'x' && *bData != *bMask) {
				return false;
			}
		}
		return (*szMask == NULL);
	}

	// for finding a signature/pattern in memory of another process
	BYTE* FindSignature(BYTE* start, const DWORD size, const char* sig, const char* mask)
	{
		BYTE* data = new BYTE[size];
		SIZE_T bytesRead;

		ReadProcessMemory(TargetProcess, start, data, size, &bytesRead);

		for (DWORD i = 0; i < size; i++) {
			if (MemoryCompare(data + i, (const BYTE*)sig, mask)) {
				return start + i;
			}
		}
		delete[] data;
		return NULL;
	}
};
