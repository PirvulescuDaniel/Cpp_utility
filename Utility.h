#pragma once
#include "pch.h"

namespace Utility
{

	std::string GUIDGenerator()
	{
		srand(static_cast<unsigned int>(time(NULL)));

		const std::string characters = "0123456789ABCDEF";
		std::string guid;

		guid += '{';
		for (auto i = 0; i < 36; i++)
		{
			if (i == 8 || i == 13 || i == 18 || i == 23) {
				guid += '-';
				continue;
			}

			const auto index = rand() % characters.size();
			guid += characters.at(index);
		}
		guid += '}';

		return guid;
	}

	std::vector<std::string> SplitByDelimiters(const std::string& aString, std::vector<std::string> aDelimiters)
	{
		std::sort(aDelimiters.begin(), aDelimiters.end(),
			[](const std::string& first, const std::string& second) {
				return first.size() > second.size();
			}
		);

		std::vector<std::string> output;
		std::string stringCopy(aString);

		size_t index{};
		size_t delimSize{};

		while (true)
		{
			size_t indexMin = std::numeric_limits<size_t>::max();

			for (const auto& delimitator : aDelimiters)
			{
				index = stringCopy.find(delimitator);
				if (index != std::string::npos && index < indexMin)
				{
					indexMin = index;
					delimSize = delimitator.size();
				}
			}

			if (indexMin == std::numeric_limits<size_t>::max())
			{
				output.push_back(stringCopy);
				break;
			}

			output.push_back(stringCopy.substr(0, indexMin));
			stringCopy = stringCopy.substr(indexMin + delimSize, stringCopy.size());
		}

		auto last = std::remove_if(output.begin(), output.end(),
			[](const std::string& obj) {
				return obj.size() == 0;
			}
		);

		output = std::vector<std::string>(output.begin(), last);
		return output;
	}


}
