#pragma once

#include <string>

namespace Antimatter
{
	/**
	 * \brief Super object.
	 */
	class Object
	{
	public:
		Object() = default;
		virtual ~Object() = default;
		virtual std::string toString();
	};
}
