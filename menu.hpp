//
// menu.hpp for  in /home/charra_s/Desktop/Bomberman
// 
// Made by Charrad Sofiane
// Login   <charra_s@epitech.net>
// 
// Started on  Sun Jun  5 18:53:13 2016 Charrad Sofiane
// Last update Sun Jun  5 20:47:54 2016 Charrad Sofiane
//

#ifndef __MENU_HPP__
# define __MENU_HPP__

#include "include/irrlicht.h"
#include "game.hpp"

class                           Menu
{
public:
  Menu(Game *b);
  ~Menu();
  irr::gui::IGUIEnvironment	*_gui;
  irr::gui::IGUIImage		*img;
  irr::video::ITexture		*tex;
  irr::gui::IGUIFont		*font;
  irr::gui::IGUIButton		*newgamebtn;
  irr::gui::IGUIButton		*multiplayerbtn;
  irr::gui::IGUIButton		*optionbtn;
  irr::gui::IGUIButton		*creditbtn;
  irr::gui::IGUIButton		*quitbtn;
  irr::gui::IGUIButton		*map1;
  irr::gui::IGUIButton		*map2;
  irr::gui::IGUIButton		*map3;

};


#endif /* !__MENU_HPP__ */
