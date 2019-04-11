//
// MenuEvent.cpp for  in /home/charra_s/Desktop/Bomberman
// 
// Made by Charrad Sofiane
// Login   <charra_s@epitech.net>
// 
// Started on  Sun Jun  5 21:15:53 2016 Charrad Sofiane
// Last update Sun Jun  5 22:24:29 2016 Charrad Sofiane
//

#include "menuEvent.hpp"
#include "game.hpp"

MenuEvent::MenuEvent(Menu *b, Game *game)
{
  if (b->newgamebtn->isPressed() == true)
    {
      //b->_gui->clear();
      // b->map1 = b->_gui->addButton(irr::core::rect<irr::s32>(780,80,880,120), 0, -1, L"Map 1");
      // b->map2 = b->_gui->addButton(irr::core::rect<irr::s32>(780,140,880,180), 0, -1, L"Map 2");
      // b->map1->setOverrideFont(b->font);
      // b->map2->setOverrideFont(b->font);
      // if (b->map1->isPressed() == true)
	// {
      //      b->newgamebtn->setVisible(true);
      b->_gui->drop();
	  Init                          *jeu = new Init(game, 2);
	// }
    }
  if (b->quitbtn->isPressed() == true)
    {
      game->_device->drop();
      return;
    }

}

MenuEvent::~MenuEvent()
{
}
