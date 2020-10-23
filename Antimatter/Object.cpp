#include "Object.h"

namespace Antimatter
{
	std::string Object::toString()
	{
		char buf[128];
		sprintf(buf, "%p", this);

		return buf;
	}
}

