//
// world3d.cpp for  in /home/sofiane/Documents/bomberman/source/engine/world3d
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun 15 16:01:15 2017 sofiane
// Last update Fri Jun 16 19:03:43 2017 sofiane
//

#include "world3d.hpp"

World3d::World3d()
{

}

World3d::~World3d()
{

}

irr::scene::ICameraSceneNode    *World3d::addCamera(Window *win, const int x, const int y, const int z)
{
  irr::scene::ICameraSceneNode *cam;

  cam = win->m_sceneManager->addCameraSceneNode(0, irr::core::vector3df(x, y, z));
  if (!cam)
    {
      win->m_device->drop();
      return (NULL);
    }
  return (cam);
}

irr::scene::IAnimatedMeshSceneNode      *World3d::createMesh(Window *win, const irr::io::path & mesh
							     , const irr::io::path & texture,
							     const int x, const int y, const int z)
{
  irr::scene::IAnimatedMeshSceneNode *asset;

  asset = win->m_sceneManager->addAnimatedMeshSceneNode(win->m_sceneManager->getMesh(mesh));
  if (!asset)
    {
      win->m_device->drop();
      return (NULL);
    }
  asset->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  asset->setMaterialTexture(0, win->m_driver->getTexture(texture));
  asset->setPosition(irr::core::vector3df(x, y, z));
  return (asset);
}
