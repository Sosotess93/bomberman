//
// Window.hpp for * in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 13:23:17 2017 sofiane
// Last update Thu Jun  1 15:20:50 2017 sofiane
//

#ifndef _WINDOW_HPP_
# define _WINDOW_HPP_

#include "../../irrlicht/include/irrlicht.h"
#include "../../irrlicht/include/SColor.h"

class				Window
{
public:
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::scene::ICameraSceneNode	*_camera;

  Window(const int x_size, const int y_size);
  ~Window();
};

#endif /* !_WINDOW_HPP_ */
