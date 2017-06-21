//
// main.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:41:04 2017 sofiane
// Last update Wed Jun 21 13:38:25 2017 sofiane
//

#include "Window.hpp"
#include "world3d.hpp"
#include "eventReceiver.hpp"
#include "myEventManager.hpp"
#include <iostream>

int		main()
{
  irr::scene::IAnimatedMeshSceneNode	*node;
  Window				*windows = new Window();
  World3d				*world = new World3d(node);

  // WINDOWS //
  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  // FIN WINDOW //
  // ADD A MESH //
  node = world->createMesh(windows, "game/sydney.md2","game/sydney.bmp", 10, 10, 10);
  // FIN ADD MESH //
  // SET ANIMATION MESH //
  node = world->setAnimation(irr::scene::EMAT_RUN, 10, node); // Animation + speed + node en question
  // FIN ANIMATION MESH //
  // ADD CAMERA //
  world->m_cam = world->addCamera(windows, 10, 10, 10); // Fentre + position X Y Z
  // FIN CAMERA //
  // SET POSTION CAMERA //
  world->m_cam = world->setCameraPosition(100, 100, 100); // Position X Y Z
  // FIN SET POSTION CAMERA //
  // EVENT //
  myEventManager receiver;
  irr::SEvent input;
  windows->m_device->setEventReceiver(&receiver);
  // FIN EVENT//
  // BOUCLE DE JEU DE IRRLICHT //
  while (windows->m_device->run())
    {
      windows->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      if (receiver.IsKeyDown(irr::KEY_KEY_R) == 1)
	return (0);
      if (receiver.IsKeyDown(irr::KEY_KEY_A) == 1)
	std::cout << "Je print A" << std::endl;
      windows->m_sceneManager->drawAll();
      windows->m_driver->endScene();
    }
  windows->m_device->drop();
  return (0);
  // FIN DE BOUCLE DE JEU DE IRRLICHT //
}
