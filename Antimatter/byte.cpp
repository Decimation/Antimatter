#include "byte.h"
#include <ostream>
#include <sstream>
#include <streambuf>


namespace Antimatter
{
	byte::byte() : byte(0)
	{
	}

	byte::byte(const unsigned char value) : m_value(value)
	{
	}

	std::string byte::ToString()
	{
		std::ostringstream stringStream;
		stringStream << static_cast<int>(m_value);
		auto copyOfStr = stringStream.str();


		return copyOfStr;
	}

	std::ostream& operator<<(std::ostream& stream, const byte& a)
	{
		return stream << "(" << static_cast<int>(a.m_value) << ")";
	}
}
