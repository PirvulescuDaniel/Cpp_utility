#pragma once
#include "pch.h"

namespace Utility
{

	std::string GUIDGenerator()
	{
		srand(static_cast<unsigned int>(time(NULL)));

		std::array<char, 16> characters = { '0','1','2','3','4','5','6','7','8','9',
						    'A','B','C','D','E','F' };

		std::string guid;

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
		guid.insert(guid.begin(), '{');

		return guid;
	}


}
