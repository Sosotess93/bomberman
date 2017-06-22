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
