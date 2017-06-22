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
