#pragma once
#include <algorithm>
#include <iostream>
#include <vector>


namespace Antimatter
{
	class Collections
	{
	public:
		/*
		Generic function to find an element in vector and also its position.
		It returns a pair of bool & int i.e.
		bool : Represents if element is present in vector or not.
		int : Represents the index of element in vector if its found else -1
		*/
		template <typename T>
		static std::pair<bool, int> FindInVector(const std::vector<T>& vecOfElements, const T& element)
		{
			std::pair<bool, int> result;
			// Find given element in vector
			auto it = std::find(vecOfElements.begin(), vecOfElements.end(), element);
			if (it != vecOfElements.end()) {
				result.second = distance(vecOfElements.begin(), it);
				result.first = true;
			} else {
				result.first = false;
				result.second = -1;
			}
			return result;
		}
	};
}
