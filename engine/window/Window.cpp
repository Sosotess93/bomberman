//
// Window.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:34:52 2017 sofiane
// Last update Thu Jun  1 15:25:26 2017 sofiane
//

#include "Window.hpp"

Window::Window(const int x, const int y)
{
  this->_device = irr::createDevice(irr::video::EDT_OPENGL,
				    irr::core::dimension2d<irr::u32>(x, y),
				    32, false, false, false);
  this->_driver = this->_device->getVideoDriver();
  this->_sceneManager = this->_device->getSceneManager();
}

Window::~Window()
{

}
