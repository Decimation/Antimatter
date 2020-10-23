#include "byte.h"
#include <ostream>
#include <sstream>
#include <streambuf>




namespace Antimatter
{
	byte::byte() : byte(0)
	{
	}

	byte::byte(unsigned char value) : m_value(value)
	{
	}

	std::string byte::toString()
	{
		std::ostringstream stringStream;
		stringStream << (int)m_value;
		std::string copyOfStr = stringStream.str();


		return copyOfStr;
	}
	
	std::ostream& operator<<(std::ostream& strm, const byte& a)
	{
		return strm << "(" << (int)a.m_value << ")";
	}
}