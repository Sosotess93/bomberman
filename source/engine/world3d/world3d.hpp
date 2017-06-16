//
// world3d.hpp for  in /home/sofiane/Documents/bomberman/source/engine/world3d
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun 15 16:01:22 2017 sofiane
// Last update Fri Jun 16 19:06:33 2017 sofiane
//

#ifndef _WORLD3D_HPP_
# define _WORLD3D_HPP_

#include "irrlicht.h"
#include "Window.hpp"

class		World3d
{
public:
  World3d();
  ~World3d();
  irr::scene::ICameraSceneNode	*addCamera(Window *win, const int x, const int y, const int z);
  irr::scene::IAnimatedMeshSceneNode *createMesh(Window *win, const irr::io::path &mesh, const irr::io::path &texture, const int x, const int y, const int z);

};

#endif /* !_WORLD3D_HPP_ */
