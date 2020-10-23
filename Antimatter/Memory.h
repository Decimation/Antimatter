#pragma once

#include <memory>
#include <vector>

namespace Antimatter
{
	class Memory
	{
	public:
		static int count;
	public:
		static bool Is64Bit();

		static void* Alloc(size_t);

		static void Free(void*);

		static size_t Size(void*);

		template <typename T>
		static T* Alloc(const size_t elemCnt)
		{
			const auto cb = elemCnt * sizeof(T);
			auto v = Alloc(cb);

			return static_cast<T*>(v);
		}
	};
}

void* operator new(size_t);
void operator delete(void*, size_t);
