// ReSharper disable CppClangTidyReadabilityRedundantDeclaration
// ReSharper disable CppClangTidyClangDiagnosticMicrosoftExceptionSpec
// ReSharper disable CppClangTidyClangDiagnosticImplicitExceptionSpecMismatch

#pragma once

#include <memory>
#include <vector>
#include <Windows.h>

#include "Common.h"

namespace Antimatter
{
	class Memory
	{
	private:
		static int count;
	public:
		

		static void* Alloc(size_t);

		static void Free(void*);

		static size_t Size(void*);

		template <typename T>
		static T* Alloc(const size_t elemCnt)
		{
			const auto cb = elemCnt * sizeof(T);
			auto* v = Alloc(cb);

			return static_cast<T*>(v);
		}
	};
}

inline bool Is64Bit()
{
	return sizeof(void*) == sizeof(llong);
}

void* operator new(std::size_t) noexcept;
void operator delete(void*);
