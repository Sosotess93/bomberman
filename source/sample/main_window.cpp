//
// main.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:41:04 2017 sofiane
// Last update Fri Jun  2 14:30:21 2017 sofiane
//

#include "Window.hpp"

int		main()
{
  Window	*windows = new Window();

  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  while (windows->m_device->run())
    {
      windows->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      windows->m_sceneManager->drawAll();
      windows->m_driver->endScene();
    }
  windows->m_device->drop();
  return (0);
}
