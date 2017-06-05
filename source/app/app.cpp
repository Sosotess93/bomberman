#include <iostream>
#include <memory>
#include "Window.hpp"
#include "player.h"
#include "world.hpp"


int main()
{
	std::shared_ptr<Window> window = std::make_shared<Window>();
	std::shared_ptr<game::player> player = std::make_shared<game::player>();
	std::shared_ptr<game::world> world = std::make_shared<game::world>();

	window->myCreateDevice(800, 600);
	if (!window->m_device)
	{
		std::cerr << "Error device window is false" << std::endl;
		return 1;
	}
	window->setDriver();
	window->setSceneManager();

	world->set("map.txt");
	
	while (window->m_device->run())
	{
		window->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
		window->m_sceneManager->drawAll();
		window->m_driver->endScene();
	}

	window->m_device->drop();
	return 0;
}