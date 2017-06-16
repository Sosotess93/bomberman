//
// main.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:41:04 2017 sofiane
// Last update Fri Jun 16 19:01:55 2017 sofiane
//

#include "Window.hpp"
#include "world3d.hpp"

int		main()
{
  Window	*windows = new Window();
  World3d	world;
  irr::scene::IAnimatedMesh *mesh;
  irr::scene::IAnimatedMeshSceneNode *node;

  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  windows->m_device->setWindowCaption(L"Class Event");//Nom de la fenetre

  node = world.createMesh(windows, "source/engine/event/media/sydney.md2","source/engine/event/media/sydney.bmp", 10, 10, 10);

  world.addCamera(windows,100, 100, 100); // ADD CAMERA :)

  while (windows->m_device->run())
    {
      windows->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      windows->m_sceneManager->drawAll();
      windows->m_driver->endScene();
    }
  windows->m_device->drop();
  return (0);
}
