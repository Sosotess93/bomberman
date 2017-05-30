#ifndef _WORLD_HPP_
#define _WORLD_HPP_

#include <array>
#include <string>
#include <vector>

namespace game
{

#define MAX_HEIGHT_FIELD 10
#define MAX_WIDTH_FIELD 10

	enum ITEM
	{
		OBSTACLE,
		PLAYER,
		ENNEMY,
		ITEM_UNKNOW
	};

	struct layout
	{
		std::vector<ITEM> m_items;
	};
	typedef layout layout;

	class world
	{
	public:
		explicit world();
		~world();
	private:
		std::array<std::array<layout, MAX_HEIGHT_FIELD>, MAX_WIDTH_FIELD> m_field;
	};
}
#endif // !_WORLD_HPP_
