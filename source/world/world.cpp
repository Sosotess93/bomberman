#include "world.hpp"

namespace game
{
	world::world()
	{
	}

	world::~world()
	{
	}

	void world::set(const std::string& fileName)
	{
		std::ifstream file(fileName);
		std::string line;
		int x = 0, y = 0;

		for (std::string line; std::getline(file, line);)
		{
			for (char c : line)
			{
				++x;
			}
			std::cout << std::endl;
			++y;
		}
		file.close();
	}
}