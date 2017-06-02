//
// Window.hpp for * in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 13:23:17 2017 sofiane
// Last update Fri Jun  2 14:07:54 2017 sofiane
//

#ifndef _WINDOW_HPP_
# define _WINDOW_HPP_

#include "irrlicht.h"

class				Window
{
public:
  Window();
  ~Window();
  int	myCreateDevice(const int x, const int y);
  int	setDriver();
  int	setSceneManager();
  irr::IrrlichtDevice		*m_device;
  irr::video::IVideoDriver	*m_driver;
  irr::scene::ISceneManager	*m_sceneManager;
  irr::scene::ICameraSceneNode	*m_camera;
};

#endif /* !_WINDOW_HPP_ */
