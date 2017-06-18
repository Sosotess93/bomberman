//
// Window.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:34:52 2017 sofiane
// Last update Fri Jun  2 14:31:59 2017 sofiane
//

#include <iostream>
#include "Window.hpp"

Window::Window()
{
  this->m_device = NULL;
  this->m_driver = NULL;
  this->m_sceneManager = NULL;
}

Window::~Window()
{

}

int	Window::myCreateDevice(const int x, const int y)
{
  this->m_device = irr::createDevice(irr::video::EDT_OPENGL,
  				     irr::core::dimension2d<irr::u32>(x, y),
  				     32, false, false, false);

  if (!this->m_device)
    {
      std::cerr << "Error : Not device" << std::endl;
      return (0);
    }
  return 1;
}

int	Window::setDriver()
{
  if (!this->m_device)
    return (0);
  this->m_driver = this->m_device->getVideoDriver();
}

int	Window::setSceneManager()
{
  if (!this->m_device)
    return (0);
  this->m_sceneManager = this->m_device->getSceneManager();
}
