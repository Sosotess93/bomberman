//
// main.cpp for  in /home/sofiane/Documents/bomberman/engine/window
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Thu Jun  1 14:41:04 2017 sofiane
// Last update Fri Jun 16 02:14:57 2017 sofiane
//

#include "Window.hpp"
#include "world3d.hpp"

int		main()
{
  Window	*windows = new Window();
  World3d	world;
  irr::scene::IAnimatedMesh *mesh;
  irr::scene::IAnimatedMeshSceneNode *node;

  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  windows->m_device->setWindowCaption(L"Class Event");//Nom de la fenetre

  // AJOUT D'UN MESH MANUELLEMENT ENCORE //
  mesh = windows->m_sceneManager->getMesh("source/engine/event/media/sydney.md2"); // Load Sydney
  if (!mesh)
    {
      windows->m_device->drop();
      return (1);
    }
  node = windows->m_sceneManager->addAnimatedMeshSceneNode(mesh);
  if (node)
    {
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      node->setMaterialTexture( 0, windows->m_driver->getTexture("source/engine/event/media/sydney.bmp") );
    }
  // FIN DE MESH //

  world.addCamera(windows, 100, 100, 100); // ADD CAMERA :)

  while (windows->m_device->run())
    {
      windows->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      windows->m_sceneManager->drawAll();
      windows->m_driver->endScene();
    }
  windows->m_device->drop();
  return (0);
}
