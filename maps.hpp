//
// maps.hpp for indie in /home/sivaku_v/rendu/Bomberman_v2
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sat Jun  4 20:08:39 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 21:36:13 2016 Vituzan Sivakumaran
//

#ifndef __MAPS_HPP__
# define __MAPS_HPP__

#include "game.hpp"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <ctime>

class		Maps
{
public:
  Maps();
  ~Maps();
  void		gen_map(Game *bomberman);
private:
  void		create_ground(Game *bomberman, irr::scene::IMetaTriangleSelector *meta, const std::string dir);
  int		create_map(Game *bomberman, irr::scene::IMetaTriangleSelector *meta, const std::string dir, const std::string map);
  void		init_collision(Game *bomberman, irr::scene::IMetaTriangleSelector *meta, const int i);
};

#endif /* !__MAPS_HPP__ */
