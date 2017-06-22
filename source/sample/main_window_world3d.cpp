#include "Window.hpp"
#include "world3d.hpp"
#include "menu.hpp"

int		main()
{
  Window	*windows = new Window();
  irr::scene::IAnimatedMeshSceneNode *node;
  World3d	*world = new World3d(node);
  irr::scene::IAnimatedMesh *mesh;


  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  windows->m_device->setWindowCaption(L"Class Event");
  Menu		*menu = new Menu(windows); // MENU
  node = world->createMesh(windows, "source/engine/event/media/sydney.md2","source/engine/event/media/sydney.bmp", 10, 10, 10); // CREATE MESH
  node = world->setAnimation(World3d::Animation::STAND, 100, node);
  world->m_cam = world->addCamera(windows, 100, 100, 100); // ADD CAMERA :)
  world->m_cam = world->setCameraPosition(20, 20, 20); // SET CAMERA POSTION
  //node = world->removeMesh(windows);
  while (windows->m_device->run())
    {
      windows->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      windows->m_sceneManager->drawAll();
      menu->m_gui->drawAll();
      windows->m_driver->endScene();
    }
  windows->m_device->drop();
  return (0);
}
