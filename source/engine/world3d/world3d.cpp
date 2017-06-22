#include "world3d.hpp"

World3d::World3d(irr::scene::IAnimatedMeshSceneNode *modele)
{
  this->m_mesh = modele;
}

World3d::~World3d()
{

}

irr::scene::IAnimatedMeshSceneNode      *World3d::createMesh(Window *win, const irr::io::path & mesh
							     , const irr::io::path & texture,
							     const int x, const int y, const int z)
{
  this->m_mesh = win->m_sceneManager->addAnimatedMeshSceneNode(win->m_sceneManager->getMesh(mesh));
  if (!this->m_mesh)
    {
      win->m_device->drop();
      return (NULL);
    }
  this->m_mesh->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  this->m_mesh->setMaterialTexture(0, win->m_driver->getTexture(texture));
  this->m_mesh->setPosition(irr::core::vector3df(x, y, z));
  return (this->m_mesh);
}

irr::scene::IAnimatedMeshSceneNode	*World3d::setMeshPosition(Window *win, const int x, const int y, const int z)
{
  this->m_cam->setPosition(irr::core::vector3df(x, y, z));
  return (this->m_mesh);
}

irr::scene::IAnimatedMeshSceneNode	*World3d::removeMesh(Window *win)
{
  //  win->m_sceneManager->getMeshCache()->removeMesh(this->m_mesh);
  this->m_mesh->drop();
  this->m_mesh = 0;
  return (this->m_mesh);

}


irr::scene::IAnimatedMeshSceneNode	*World3d::setAnimation(irr::scene::EMD2_ANIMATION_TYPE anim, irr::f32 speed, irr::scene::IAnimatedMeshSceneNode *node)
{
  //  irr::scene::IAnimatedMeshSceneNode *node;
  node->setMD2Animation(anim);
  node->setAnimationSpeed(speed);
  return (node);
}

irr::scene::ICameraSceneNode		*World3d::setCameraPosition(const int x, const int y, const int z)
{
  this->m_cam->setPosition(irr::core::vector3df(x, y, z));
  return (this->m_cam);
}

irr::scene::ICameraSceneNode		*World3d::addCamera(Window *win, const int x, const int y, const int z)
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
