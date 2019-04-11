//
// bomb.hpp for bomb in /home/sivaku_v/rendu/Bomberman
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sun Jun  5 14:28:41 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 18:36:26 2016 Vituzan Sivakumaran
//

#ifndef __BOMB_HPP__
# define __BOMB_HPP__

#include <thread>
#include <chrono>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>
#include "include/irrlicht.h"
#include "game.hpp"
#include "perso.hpp"
#include "eventReceiver.hpp"

class					Game;

class					Bomb
{
public:
  irr::scene::IAnimatedMeshSceneNode	*_bomb;
public:
  Bomb(Game *bomberman, Perso *perso);
  ~Bomb();

private:
  void	explode(irr::scene::IAnimatedMeshSceneNode *bomb);
};

#endif /* !__BOMB_HPP__ */
