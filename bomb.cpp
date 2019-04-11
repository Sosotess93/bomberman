//
// bomb.cpp for bomb in /home/sivaku_v/rendu/Bomberman
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sun Jun  5 14:28:47 2016 Vituzan Sivakumaran
// Last update Mon Jun 13 13:45:57 2016 Charrad Sofiane
//

#include "bomb.hpp"

Bomb::Bomb(Game *bomberman, Perso *perso)
{
  irr::scene::IAnimatedMeshSceneNode *asset;
  irr::core::vector3df persop;

  persop = perso->_perso->getPosition();
  persop.Y = -20;
  asset = bomberman->_sceneManager->addAnimatedMeshSceneNode(bomberman->_sceneManager->getMesh("Textures/MegaBomb/MegaBomb.obj"));
  asset->setMaterialFlag(irr::video::EMF_LIGHTING, false);
  asset->setMaterialTexture(3, bomberman->_driver->getTexture("Textures/MegaBomb/textureA.png"));
  asset->setMaterialTexture(3, bomberman->_driver->getTexture("Textures/MegaBomb/textureB.png"));
  asset->setMaterialTexture(3, bomberman->_driver->getTexture("Textures/MegaBomb/textureC.png"));
  asset->setPosition(persop);
  _bomb = asset;
  std::thread ex(&Bomb::explode, this, asset);
  ex.detach();
  //  bomb->remove();
}

Bomb::~Bomb()
{

}

void	Bomb::explode(irr::scene::IAnimatedMeshSceneNode *bomb)
{
  Mix_Music *tap;

  std::this_thread::sleep_for(std::chrono::milliseconds(3000));
  //    SDL_Init(SDL_INIT_AUDIO);
  //  Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024);
  //  Mix_VolumeMusic(50);
  //  tap = Mix_LoadMUS("asset/explosion.wav");
  // Mix_PlayMusic(tap, 1);
  std::cout << "BOOM" << std::endl;
  //  bomb->setVisible(false);
  bomb->remove();
}
