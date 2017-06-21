//
// main.cpp for  in /home/sofiane/Documents/bomberman/source/engine/test
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue Jun 20 23:21:30 2017 sofiane
// Last update Wed Jun 21 01:43:07 2017 sofiane
//

#include "eventmanager.hpp"
#include <iostream>

int	main(void)
{

  //Device, driver et graphe de scene.
  irr::IrrlichtDevice* device = irr::createDevice(irr::video::EDT_OPENGL,
						  irr::core::dimension2d<irr::u32>(800,800),32,false,true,false);
  irr::video::IVideoDriver* driver = device->getVideoDriver ();
  irr::scene::ISceneManager *sceneManager = device->getSceneManager ();

  //On rend invisible le curseur.
  device->getCursorControl ()-> setVisible(true);

  //Sydney
  irr::scene::IAnimatedMeshMD2* modele;
  modele = (irr::scene::IAnimatedMeshMD2*)sceneManager->getMesh("game/Marvin.md2");
  irr::scene::IAnimatedMeshSceneNode* Nmodele =
    sceneManager->addAnimatedMeshSceneNode(modele);

  //On modifie les proprietes de Sydney
  Nmodele->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  Nmodele->setFrameLoop(0, 0);
  Nmodele->setMaterialTexture( 0, driver->getTexture("game/Marvin.jpg") );

  //La camera
  //On cree la keymap associe a la camera
  irr::SKeyMap keyMap[5];
  //avancer
  keyMap[0].Action = irr::EKA_MOVE_FORWARD;
  keyMap[0].KeyCode = irr::KEY_KEY_Z;
  //reculer
  keyMap[1].Action = irr::EKA_MOVE_BACKWARD;
  keyMap[1].KeyCode = irr::KEY_KEY_S;
  //a gauche
  keyMap[2].Action = irr::EKA_STRAFE_LEFT;
  keyMap[2].KeyCode = irr::KEY_KEY_Q;
  //a droite
  keyMap[3].Action = irr::EKA_STRAFE_RIGHT;
  keyMap[3].KeyCode = irr::KEY_KEY_D;
  //saut
  keyMap[4].Action = irr::EKA_JUMP_UP;
  keyMap[4].KeyCode = irr::KEY_SPACE;

  //La camera
  irr::scene::ICameraSceneNode *camera;
  camera = sceneManager->addCameraSceneNodeFPS (0, 100.0f, 0.3f, -1, keyMap, 5, false, 0.4);

  //On cree le capteur d'event et on l'associe au device.
  MyEventReceiver receiver;
  device->setEventReceiver(&receiver);

  //La boucle de rendu
  while (device->run())
    {
      driver->beginScene(true, true, irr::video::SColor(0,200,200,200));
      if (receiver.IsKeyDown(irr::KEY_KEY_R))
      	return (0);
      sceneManager->drawAll ();
      driver->endScene ();
    }
  device->drop ();
  return 0;
}
