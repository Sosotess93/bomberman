//
// world3d.cpp for  in /home/sofiane/Documents/bomberman/source/engine/world3d
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun 15 16:01:15 2017 sofiane
// Last update Fri Jun 16 02:15:58 2017 sofiane
//

#include "world3d.hpp"

irr::scene::ICameraSceneNode    *World3d::addCamera(Window *win, const int x, const int y, const int z)
{
  win->m_sceneManager->addCameraSceneNode(0, irr::core::vector3df(x, y, z));
}
