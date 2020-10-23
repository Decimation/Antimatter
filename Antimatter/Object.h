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
		virtual ~Object() = default;
		virtual std::string toString();
	};

}
