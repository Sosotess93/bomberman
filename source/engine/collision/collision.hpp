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
