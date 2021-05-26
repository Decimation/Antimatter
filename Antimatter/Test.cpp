// Antimatter.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>


#include "byte.h"
#include "Collections.h"
#include "Console.h"
#include "Memory.h"
#include "Object.h"
#include "SigScanner.h"
#include "Strings.h"


#include <numeric>
#include <vector>
#include <iostream>
#include <concepts>


#include <boost/any.hpp>
#include <boost/format.hpp>


using namespace std;
using namespace Antimatter;

template <typename T> requires std::integral<T> || std::floating_point<T>
constexpr double Average(std::vector<T> const& vec)
{
	const double sum = std::accumulate(vec.begin(), vec.end(), 0.0);
	return sum / vec.size();
}

void ver()
{
	cout << boost::format("%1% %2% %3% %4%") % __cplusplus % _MSVC_LANG % _MSC_VER % _MSC_FULL_VER << std::endl;
}

int main() noexcept
{
	boost::any a = 1;
	printf("%s\n", a.type().name());


	ver();

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
