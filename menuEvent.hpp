//
// menuEvent.hpp for  in /home/charra_s/Desktop/Bomberman
// 
// Made by Charrad Sofiane
// Login   <charra_s@epitech.net>
// 
// Started on  Sun Jun  5 21:13:46 2016 Charrad Sofiane
// Last update Sun Jun  5 22:00:56 2016 Charrad Sofiane
//

#ifndef __MENU_EVENT_HPP__
# define __MENU_EVENT_HPP__

#include "include/irrlicht.h"
#include "menu.hpp"
#include "game.hpp"
#include "init.hpp"

class                           MenuEvent
{
public:
  MenuEvent(Menu *b, Game *v);
  ~MenuEvent();
};

#endif
