#include "Object.h"
#include "Common.h"

namespace Antimatter
{
	std::string Object::ToString()
	{
		QuickFormat(buf, "%p", static_cast<void*>(this));

		return buf;
	}
}
