//
// init.cpp for indie in /home/sivaku_v/rendu/Bomberman
//
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
//
// Started on  Sun Jun  5 21:44:01 2016 Vituzan Sivakumaran
// Last update Wed Jun 14 00:11:06 2017 sofiane
//

#include "init.hpp"

Init::Init(Game *bomberman, const int player)
{
  Maps				*map = new Maps();
  //irr::scene::ICameraSceneNode	*camera;

  //Curseur Invisible
  bomberman->_device->getCursorControl()->setVisible(true);
  //Light
  bomberman->_sceneManager->setAmbientLight(irr::video::SColorf(1.0, 1.0, 1.0, 0.0));
  //Perso
  bomberman->gen_perso(bomberman, player);
  //Camera
  bomberman->_camera = bomberman->addCamera(1, bomberman->_perso[0]->_perso);
  //Map gen
  map->gen_map(bomberman);
}
