//
// app.cpp for  in /home/sofiane/Documents/bomberman
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Sun Jun 18 23:00:24 2017 sofiane
// Last update Sun Jun 18 23:08:05 2017 sofiane
//

#include <iostream>
#include <memory>
#include "Window.hpp"
#include "player.h"
#include "eventReceiver.hpp"
#include "world3d.hpp"

static void	eventCamera(World3d* w, const eventReceiver::inputCase& e)
{
	std::cout << "Cam" << std::endl;
	switch (e)
	{
	case eventReceiver::KEY_UP:
	{
		w->setCameraPosition(
			w->m_cam->getPosition().X,
			w->m_cam->getPosition().Y + 100,
			w->m_cam->getPosition().Z);
	}break;
	case eventReceiver::KEY_DOWN:
	{
		w->setCameraPosition(
			w->m_cam->getPosition().X,
			w->m_cam->getPosition().Y + 100,
			w->m_cam->getPosition().Z);
	}break;
	case eventReceiver::KEY_RIGHT:
	{
		w->setCameraPosition(
			w->m_cam->getPosition().X,
			w->m_cam->getPosition().Y + 10,
			w->m_cam->getPosition().Z);
	}break;
	case eventReceiver::KEY_LEFT:
	{
		w->setCameraPosition(
			w->m_cam->getPosition().X,
			w->m_cam->getPosition().Y - 10,
			w->m_cam->getPosition().Z);
	}break;
	default:
		break;
	}
}

int	main()
{
  Window* window = new Window();
  game::player player;


  if (window->myCreateDevice(800, 600) == 0)
    return (1);

  if (window->setDriver() == 0)
    {
      std::cerr << "Error on setDriver" << std::endl;
      //return 1;
    }

  if (window->setSceneManager() == 0)
    {
      std::cerr << "Error on setSceneManager" << std::endl;
      //return 1;
    }

  common::Location<float> locationCam(player.getLocation());

  World3d world3D(player.getMesh());
  world3D.m_cam = world3D.addCamera(
				    window,
				    player.getLocation().m_x,
				    player.getLocation().m_y + 100,
				    player.getLocation().m_z);

  player.setMesh(world3D.createMesh(window, "game/sydney.md2", "game/sydney.bmp", 0, 0, 0));
  if (player.getMesh() == NULL)
    {
      std::cout << "Error on setMesh" << std::endl;
      return 1;
    }

  eventReceiver event;
  irr::SEvent input;
  eventReceiver::inputCase key;
  window->m_device->setEventReceiver(&event);

  while (window->m_device->run())
    {
      if (event.OnEvent(input))
	{
	  std::cout << "Event Recue" << std::endl;
	  key = event.lastKey();
	  if (player.event(key))
	    {
	      world3D.setCameraPosition(
					player.getLocation().m_x,
					player.getLocation().m_y + 100,
					player.getLocation().m_y
					);
	    }
	  else
	    {
	      eventCamera(&world3D, key);
	    }
	}
      window->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      window->m_sceneManager->drawAll();
      window->m_driver->endScene();
    }

  window->m_device->drop();
  delete window;
  return 0;
}
