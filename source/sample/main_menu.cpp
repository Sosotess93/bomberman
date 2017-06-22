#include "Window.hpp"
#include "menu.hpp"

int		main()
{
  Window	*windows = new Window();

  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  Menu          *menu = new Menu(windows);
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
