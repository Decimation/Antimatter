#pragma once
#include <ostream>

#include "Object.h"

namespace Antimatter
{
	class byte : Object
	{
	private:
		unsigned char m_value;
	private:
		friend std::ostream& operator<<(std::ostream&, const byte&);
	public:
		byte();

		byte(unsigned char);

		std::string toString() override;
		
	};
}


std::ostream& operator<<(std::ostream&, const Antimatter::byte&);