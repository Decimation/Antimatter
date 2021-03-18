// ReSharper disable CppParameterNamesMismatch
#include "Memory.h"
#include "Common.h"
#include "Windows.h"
#include "debugapi.h"

using namespace std;

int Antimatter::Memory::count = 0;

namespace Antimatter
{
	void* Memory::Alloc(const size_t cb)
	{
		auto* const p = malloc(cb);

		if (p) {
			memset(p, 0, cb);
		}
		
		Memory::count++;

		//printf("Alloc %d\n", cb);


		//OutputDebugString(L"alloc");

		return p;
	}

	void Memory::Free(void* v)
	{
		//printf("Free %p", v);

		count--;

		//OutputDebugString(L"free");

		free(v);
	}

	size_t Memory::Size(void* v)
	{
		return _msize(v);
	}

	
}


void* operator new(std::size_t cb) noexcept
{
	return Antimatter::Memory::Alloc(cb);
}

void operator delete(void* p)
{
	Antimatter::Memory::Free(p);
}
