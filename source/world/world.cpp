#include "world.hpp"

namespace game
{
	world::world():
		m_field()
	{

	}

	world::~world()
	{
	}

	void world::add(ITEM item, int x, int y)
	{
		if (y >= MAX_HEIGHT_FIELD || x >= MAX_WIDTH_FIELD)
			return;
		m_field.at(y).at(x).m_items.push_back(item);
	}


	bool world::is(ITEM item, int x, int y)
	{
		if (y >= MAX_HEIGHT_FIELD || x >= MAX_WIDTH_FIELD)
			return;
		auto items = m_field.at(y).at(x).m_items;
		auto _it = std::find(items.begin(), items.end(), item);
		if (_it != items.end())
			return true;
		return false;
	}
}