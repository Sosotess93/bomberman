#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <fstream>
#include "common.hpp"

namespace game
{

#define MAX_HEIGHT_FIELD 20
#define MAX_WIDTH_FIELD 20

	class world
	{
	public:
		explicit world();
		~world();
		
		void set(const std::string& fileName);
	private:
	};
}
#endif // !_WORLD_HPP_
