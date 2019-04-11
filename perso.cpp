//
// perso.cpp for indie in /home/sivaku_v/rendu/Bomberman_v2
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sat Jun  4 19:31:36 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 21:37:10 2016 Vituzan Sivakumaran
//

#include "perso.hpp"

Perso::Perso(irr::scene::IAnimatedMeshSceneNode *perso, const std::string name) : _perso(perso),  _name(name), _life(5)
{
  if (perso)
    std::cout << "Perso created" << std::endl;
}

Perso::~Perso()
{

}
