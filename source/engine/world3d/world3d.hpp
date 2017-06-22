#ifndef _WORLD3D_HPP_
# define _WORLD3D_HPP_

#include "irrlicht.h"
#include "Window.hpp"

class					World3d
{
public:
  enum	Animation
    {
      STAND = irr::scene::EMAT_STAND,
      RUN =  irr::scene::EMAT_RUN,
    };
  irr::scene::IAnimatedMeshSceneNode	*m_mesh;
  irr::scene::ICameraSceneNode		*m_cam;

  World3d(irr::scene::IAnimatedMeshSceneNode *modele);
  ~World3d();

  // CAMERA
  irr::scene::ICameraSceneNode		*addCamera(Window *win, const int x, const int y, const int z);
  // SET CAMERA POSITION
  irr::scene::ICameraSceneNode		*setCameraPosition(const int x, const int y, const int z);
  // SET ANIMATION
  irr::scene::IAnimatedMeshSceneNode    *setAnimation(irr::scene::EMD2_ANIMATION_TYPE anim, irr::f32 speed, irr::scene::IAnimatedMeshSceneNode *node);
  // CREATE MESH
  irr::scene::IAnimatedMeshSceneNode	*createMesh(Window *win, const irr::io::path &mesh, const irr::io::path &texture, const int x, const int y, const int z);
  // SET MESH POSITION
  irr::scene::IAnimatedMeshSceneNode	*setMeshPosition(Window *win, const int x, const int y, const int z);
  //REMOVE MESH
  irr::scene::IAnimatedMeshSceneNode	*removeMesh(Window *win);

};

#endif /* !_WORLD3D_HPP_ */
