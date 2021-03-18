// ReSharper disable CppInconsistentNaming
#pragma once
#include <ostream>

#include "Object.h"

namespace Antimatter
{
	class byte final : Object
	{
	private:
		unsigned char m_value;
	private:
		friend std::ostream& operator<<(std::ostream&, const byte&);
	public:
		byte();

		byte(unsigned char);

		std::string ToString() override;
		
	};
}


std::ostream& operator<<(std::ostream&, const Antimatter::byte&);