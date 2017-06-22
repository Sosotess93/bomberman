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
