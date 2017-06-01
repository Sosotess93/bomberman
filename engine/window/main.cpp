//
// main.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:41:04 2017 sofiane
// Last update Thu Jun  1 15:24:29 2017 sofiane
//

#include "Window.hpp"

int		main()
{
  Window	*windows = new Window(1024, 1024);

  while (windows->_device->run())
    {
      windows->_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      windows->_sceneManager->drawAll();
      windows->_driver->endScene();
    }
  windows->_device->drop();
  return (0);
}
