//
// menu.hpp for  in /home/sofiane/Documents/bomberman/source/engine/menu
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Sun Jun 18 17:24:20 2017 sofiane
// Last update Sun Jun 18 17:36:34 2017 sofiane
//

#ifndef __MENU_HPP__
# define __MENU_HPP__

#include "irrlicht.h"
#include "Window.hpp"

  class                           Menu
  {
  public:
    Menu(Window *win);
    ~Menu();
    irr::gui::IGUIEnvironment     *m_gui;
    irr::gui::IGUIImage           *m_img;
    irr::video::ITexture          *m_tex;
    irr::gui::IGUIFont            *m_font;
    irr::gui::IGUIButton          *m_newGame;
    irr::gui::IGUIButton          *m_multiplayer;
    irr::gui::IGUIButton          *m_option;
    irr::gui::IGUIButton          *m_credit;
    irr::gui::IGUIButton          *m_quit;
  };

#endif /* !__MENU_HPP__ */
