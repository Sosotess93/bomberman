//
// game.hpp for indie in /home/sivaku_v/rendu/Bomberman_v2
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sat Jun  4 19:02:13 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 22:54:52 2016 Vituzan Sivakumaran
//

#ifndef __GAME_HPP__
# define __GAME_HPP__

#include "include/irrlicht.h"
#include "perso.hpp"
#include "eventReceiver.hpp"

class				Game
{
public:
  irr::IrrlichtDevice		*_device;
  irr::video::IVideoDriver	*_driver;
  irr::scene::ISceneManager	*_sceneManager;
  irr::scene::ICameraSceneNode	*_camera;
  Perso				*_perso[3];
public:
  Game(const int x_size, const int y_size);
  ~Game();
  irr::scene::ICameraSceneNode	*addCamera(const int type, irr::scene::IAnimatedMeshSceneNode *perso);
  void	addPerso(Perso *perso);
  irr::scene::IAnimatedMeshSceneNode	*create_perso(Game *bomberman, const int x, const int y, const int z);
  int		gen_perso(Game *bomberman, int nb);
};

#endif /* !__GAME_HPP__ */
