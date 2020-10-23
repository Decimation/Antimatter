#include "Memory.h"
#include "Common.h"

namespace Antimatter
{
	bool Memory::Is64Bit()
	{
		return sizeof(void*) == sizeof(llong);
	}
}

