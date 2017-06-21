//
// collision.cpp for  in /home/sofiane/Documents/bomberman/source/engine/collision
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Wed Jun 21 14:29:41 2017 sofiane
// Last update Wed Jun 21 14:40:23 2017 sofiane
//

#include "collision.hpp"

Collision::Collision()
{

}

bool	Collision::collisions(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two, int size)
{
  if(one->getAbsolutePosition().getDistanceFrom(two->getAbsolutePosition()) < size)
    return true;
  return false;
}

bool	Collision::collisiones(irr::scene::ISceneNode* one, irr::scene::ISceneNode* two)
{
  if (one->getBoundingBox().intersectsWithBox(two->getBoundingBox()))
    return true;
  return false;
}
