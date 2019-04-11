//
// menu.cpp for  in /home/charra_s/Desktop/Bomberman
// 
// Made by Charrad Sofiane
// Login   <charra_s@epitech.net>
// 
// Started on  Sun Jun  5 18:52:56 2016 Charrad Sofiane
// Last update Sun Jun  5 22:31:24 2016 Charrad Sofiane
//

#include "menu.hpp"

Menu::Menu(Game *b)
{
  this->_gui = b->_device->getGUIEnvironment();
  this->tex = b->_driver->getTexture("./asset/background.jpg");
  this->img = this->_gui->addImage(irr::core::rect<irr::s32>(10,10, 1000,850));
  this->img->setImage(this->tex);
  this->img->setScaleImage(true);
  b->_driver->removeTexture(this->tex);
  this->font = this->_gui->getFont("./asset/fontlucida.png");
  this->newgamebtn = this->_gui->addButton(irr::core::rect<irr::s32>(100,80,200,120), 0, -1, L"Nouveau jeu");
  this->multiplayerbtn = this->_gui->addButton(irr::core::rect<irr::s32>(100,140,200,180), 0, -1, L"Multijoueur");
  this->optionbtn = this->_gui->addButton(irr::core::rect<irr::s32>(100,200,200,240), 0, -1, L"Options");
  this->creditbtn = this->_gui->addButton(irr::core::rect<irr::s32>(100,260,200,300), 0, -1, L"Credits");
  this->quitbtn = this->_gui->addButton(irr::core::rect<irr::s32>(100,320,200,360), 0, -1, L"Quitter");
  this->newgamebtn->setOverrideFont(font);
  this->multiplayerbtn->setOverrideFont(font);
  this->optionbtn->setOverrideFont(font);
  this->creditbtn->setOverrideFont(font);
  this->quitbtn->setOverrideFont(font);
}


Menu::~Menu()
{
}
