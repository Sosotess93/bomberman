//
// menu.cpp for  in /home/sofiane/Documents/bomberman/source/engine/menu
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Sun Jun 18 17:27:31 2017 sofiane
// Last update Sun Jun 18 17:40:52 2017 sofiane
//

#include "menu.hpp"

Menu::Menu(Window *win)
{
  this->m_gui = win->m_device->getGUIEnvironment();
  this->m_tex = win->m_driver->getTexture("./asset/back.jpg");
  this->m_img = this->m_gui->addImage(irr::core::rect<irr::s32>(10,10, 1000,850));
  this->m_img->setImage(this->m_tex);
  this->m_img->setScaleImage(true);
  win->m_driver->removeTexture(this->m_tex);
  this->m_font = this->m_gui->getFont("./asset/fontlucida.png");
  this->m_newGame = this->m_gui->addButton(irr::core::rect<irr::s32>(100,80,200,120), 0, -1, L"Nouveau jeu");
  this->m_multiplayer = this->m_gui->addButton(irr::core::rect<irr::s32>(100,140,200,180), 0, -1, L"Multijoueur");
  this->m_option = this->m_gui->addButton(irr::core::rect<irr::s32>(100,200,200,240), 0, -1, L"Options");
  this->m_credit = this->m_gui->addButton(irr::core::rect<irr::s32>(100,260,200,300), 0, -1, L"Credits");
  this->m_quit = this->m_gui->addButton(irr::core::rect<irr::s32>(100,320,200,360), 0, -1, L"Quitter");
  this->m_newGame->setOverrideFont(m_font);
  this->m_multiplayer->setOverrideFont(m_font);
  this->m_option->setOverrideFont(m_font);
  this->m_credit->setOverrideFont(m_font);
  this->m_quit->setOverrideFont(m_font);
}

Menu::~Menu()
{
}
