#include <iostream>
#include <memory>
#include "player.h"

int main()
{
	std::shared_ptr<game::player> player = std::make_shared<game::player>();
	player->showStats();
	player->putBomb();
	player->setCharacteristic(game::characteristique(12, 1));
	player->showStats();
	player->putBomb();
	player->setLocation(common::Location<float>(1, 10, 5));
	player->showStats();
	player->putBomb();
	return 0;
}