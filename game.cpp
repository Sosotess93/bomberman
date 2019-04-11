//
// game.cpp for indie in /home/sivaku_v/rendu/Bomberman_v2
//
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
//
// Started on  Sat Jun  4 19:02:18 2016 Vituzan Sivakumaran
// Last update Fri Jun 16 19:38:37 2017 sofiane
//

#include "game.hpp"

Game::Game(const int x_size, const int y_size)
{
  this->_perso[0] = NULL;
  this->_perso[1] = NULL;
  this->_device = irr::createDevice(irr::video::EDT_OPENGL,
				    irr::core::dimension2d<irr::u32>(x_size, y_size),
				    32, false, false, false);
  this->_driver = this->_device->getVideoDriver();
  this->_sceneManager = this->_device->getSceneManager();
}

Game::~Game()
{

}

irr::scene::ICameraSceneNode	*Game::addCamera(const int type, irr::scene::IAnimatedMeshSceneNode *perso)
{
  irr::scene::ICameraSceneNode *camera;

  if (type == 1)
    camera = this->_sceneManager->addCameraSceneNode(0, irr::core::vector3df(-50.0f, 800.0f, -50.0f));
  else if (type == 2)
    camera = this->_sceneManager->addCameraSceneNodeFPS(0);
  return (camera);
}

irr::scene::IAnimatedMeshSceneNode	*Game::create_perso(Game *bomberman, const int x, const int y, const int z)
{
  irr::scene::IAnimatedMeshSceneNode *asset;

  asset = bomberman->_sceneManager->addAnimatedMeshSceneNode(bomberman->_sceneManager->getMesh("asset/Marvin.md2"));
  asset->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  asset->setMaterialTexture(0, bomberman->_driver->getTexture("asset/Marvin.jpg"));
  asset->setPosition(irr::core::vector3df(x, y, z));
  return (asset);
}

void		Game::addPerso(Perso *perso)
{
  if (this->_perso[0])
    this->_perso[1] = perso;
  else
    this->_perso[0] = perso;
}

int		Game::gen_perso(Game *bomberman, int nb)
{
  Perso		*perso;

  perso = new Perso(create_perso(bomberman, 40, 100, 40), "IronMan");
  bomberman->addPerso(perso);
  if (nb >= 2)
    {
      perso = new Perso(create_perso(bomberman, 660, 100, 40), "IronMan");
      bomberman->addPerso(perso);
    }
}
