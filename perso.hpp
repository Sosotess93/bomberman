//
// perso.hpp for indie in /home/sivaku_v/rendu/Bomberman_v2
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sat Jun  4 19:31:32 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 21:37:04 2016 Vituzan Sivakumaran
//

#ifndef __PERSO_HPP__
# define __PERSO_HPP__

#include "include/irrlicht.h"
#include <iostream>

class					Perso
{
public:
  irr::scene::IAnimatedMeshSceneNode	*_perso;
  int					_life;
  std::string				_name;
public:
  Perso(irr::scene::IAnimatedMeshSceneNode *perso, const std::string name);
  ~Perso();
};

#endif /* !__PERSO_HPP__ */
