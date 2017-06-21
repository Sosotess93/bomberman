
//
// collision.hpp for  in /home/sofiane/Documents/bomberman/source/engine/collision
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Wed Jun 21 14:30:00 2017 sofiane
// Last update Wed Jun 21 14:40:57 2017 sofiane
//

#ifndef _COLLISION_HPP_
# define _COLLISION_HPP_

#include "irrlicht.h"

class		Collision
{
public:
  Collision();
  ~Collision();
  bool collisions(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two, int size);
  bool collisiones(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two);
};

#endif /* !_COLLISION_HPP_ */
