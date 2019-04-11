//
// eventReceiver.hpp for indie in /home/sivaku_v/rendu/Bomberman
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sun Jun  5 18:11:24 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 21:38:46 2016 Vituzan Sivakumaran
//

#ifndef __EVENTRECEIVER_HPP__
# define __EVENTRECEIVER_HPP__

#include "include/irrlicht.h"
#include <iostream>
#include "game.hpp"
#include "bomb.hpp"

class Game;

class EventReceiver : public irr::IEventReceiver
{
public:
  irr::scene::IAnimatedMeshSceneNode* perso1;
  irr::scene::IAnimatedMeshSceneNode* perso2;

  bool	_1animRun;
  bool	_1isMoving_up;
  bool	_1isMoving_down;
  bool	_1isMoving_left;
  bool	_1isMoving_right;
  bool	_1bombe_posed;

  bool	_2animRun;
  bool	_2isMoving_up;
  bool	_2isMoving_down;
  bool	_2isMoving_left;
  bool	_2isMoving_right;
  bool	_2bombe_posed;

public:
  EventReceiver(Perso **perso);
  int	first_perso(const irr::SEvent &event);
  int	second_perso(const irr::SEvent &event);
  virtual bool OnEvent(const irr::SEvent &event);
  void	majPosMesh1();
  void	majPosMesh2();

  void	majAnimMeshUp1();
  void	majAnimMeshUp2();

  int	is_1_pressed() const;
  int	is_2_pressed() const;

  void	majBomb(Game *bomberman);
};

#endif /* !__EVENTRECEIVER0_HPP__ */
