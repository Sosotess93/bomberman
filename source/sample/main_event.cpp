#include "Window.hpp"
#include "world3d.hpp"
#include "eventReceiver.hpp"
#include "myEventManager.hpp"
#include "collision.hpp"
#include <iostream>

int		main()
{
  irr::scene::IAnimatedMeshSceneNode	*node;
  Window				*windows = new Window();
  World3d				*world = new World3d(node);
  Collision				*col; // Appel de la class Collision
  // WINDOWS //
  windows->myCreateDevice(800, 600);
  if (!windows->m_device)
    return (0);
  windows->setDriver();
  windows->setSceneManager();
  // FIN WINDOW //
  // ADD A MESH //
  //  node = world->createMesh(windows, "game/sydney.md2","game/sydney.bmp", 10, 10, 10);
  // FIN ADD MESH //
  // SET ANIMATION MESH //
  //node = world->setAnimation(irr::scene::EMAT_RUN, 10, node); // Animation + speed + node en question
  // FIN ANIMATION MESH //
  // ADD CAMERA //
  world->m_cam = world->addCamera(windows, 10, 10, 10); // Fentre + position X Y Z
  // FIN CAMERA //
  // SET POSTION CAMERA //
  world->m_cam = world->setCameraPosition(100, 100, 100); // Position X Y Z
  // FIN SET POSTION CAMERA //
  // CUBE //
  irr::scene::ISceneNode* cube = windows->m_sceneManager->addCubeSceneNode();
  cube->setPosition(irr::core::vector3df(0,0,5));
    // FIN CUBE //
  // SPHERE //
  irr::scene::ISceneNode* sphere = windows->m_sceneManager->addSphereSceneNode();
  sphere->setPosition(irr::core::vector3df(0,0,100));
  // FIN SPHERE//
  // EVENT //
  myEventManager receiver;
  irr::SEvent input;
  windows->m_device->setEventReceiver(&receiver);
  // FIN EVENT//
  // BOUCLE DE JEU DE IRRLICHT //
  while (windows->m_device->run())
    {
      windows->m_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
      if (receiver.IsKeyDown(irr::KEY_KEY_R) == 1) // EVENT TOUCHE R POUR QUITTER
	return (0);
      if (receiver.IsKeyDown(irr::KEY_KEY_W) == 1) // EVENT TOUCHE W POUR BOUGER LE CUBE
	cube->setPosition(cube->getPosition() + irr::core::vector3df(0,0,5));
      if (receiver.IsKeyDown(irr::KEY_KEY_S) == 1) // EVENT TOUCHE W POUR BOUGER LE CUBE
	cube->setPosition(cube->getPosition() - irr::core::vector3df(0,0,5));

      if (col->collisions(cube, sphere, 1)) // CHECK COLLISION ENTRE SPHERE ET CUBE
	std::cout<<"Collided!"<< std::endl;
      windows->m_sceneManager->drawAll();
      windows->m_driver->endScene();
    }
  windows->m_device->drop();
  return (0);
  // FIN DE BOUCLE DE JEU DE IRRLICHT //
}
