//
// maint.cpp for  in /home/sofiane/Documents/bomberman/source/engine/event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Fri Jun  2 21:11:05 2017 sofiane
// Last update Fri Jun  2 21:54:04 2017 sofiane
//

#include "eventReceiver.hpp"

int	main()
{
  irr::IrrlichtDevice *device;
  irr::video::IVideoDriver *driver;
  irr::scene::IAnimatedMesh *mesh;
  irr::scene::IAnimatedMeshSceneNode *node;
  irr::scene::ISceneManager *smgr;

  device = irr::createDevice(irr::video::EDT_OPENGL,
						  irr::core::dimension2d<irr::u32>(600, 600),
						  32, false, false, false); // Création du device

  if (!device)
    return (1); // Verification

  device->setWindowCaption(L"Class Event"); // Nom fenêtre
  driver = device->getVideoDriver();
  smgr = device->getSceneManager();
  mesh = smgr->getMesh("source/engine/event/media/sydney.md2"); // Load Sydney
  if (!mesh)
    {
      device->drop();
      return (1);
    }
   node = smgr->addAnimatedMeshSceneNode(mesh);
  if (node)
    {
      node->setMaterialFlag(irr::video::EMF_LIGHTING, false);
      node->setMD2Animation(irr::scene::EMAT_STAND);
      node->setMaterialTexture( 0, driver->getTexture("source/engine/event/media/sydney.bmp") );
    }

  smgr->addCameraSceneNode(0, irr::core::vector3df(0,30,-40), irr::core::vector3df(0,5,0));
  eventReceiver receiver(node); // Appel de la class EVENT
  device->setEventReceiver(&receiver); // Attribuer les event à un device
  while(device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(255,100,101,140));
      smgr->drawAll();
      driver->endScene();
    }
  device->drop();
  return (0);
}
