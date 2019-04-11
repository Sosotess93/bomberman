// main.cpp for indie in /home/sivaku_v/rendu/Bomberman_v2
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sat Jun  4 19:01:29 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 23:28:54 2016 Vituzan Sivakumaran
//

#include "menu.hpp"
#include "menuEvent.hpp"
#include "game.hpp"
#include "perso.hpp"
#include "maps.hpp"
#include "init.hpp"
#include <SDL/SDL_mixer.h>
#include <SDL/SDL.h>

int				main()
{
  Game				*bomberman = new Game(1024, 1024);
  Init				*jeu = new Init(bomberman, 2);
  Menu				*menu = new Menu(bomberman);
  SDL_Init(SDL_INIT_AUDIO);

   EventReceiver receiver(bomberman->_perso);
   bomberman->_device->setEventReceiver(&receiver);
   while (bomberman->_device->run())
     {
       bomberman->_driver->beginScene(true, true, irr::video::SColor(200, 200, 200, 200));
       menu->_gui->drawAll();
       MenuEvent *event = new MenuEvent(menu, bomberman);
       bomberman->_camera->setTarget(bomberman->_perso[0]->_perso->getPosition());
       receiver.majPosMesh1();
       if (bomberman->_perso[1])
	 receiver.majPosMesh2();
       receiver.majBomb(bomberman);

       bomberman->_sceneManager->drawAll();
       bomberman->_driver->endScene();
     }
   bomberman->_device->drop();
   return (0);
}
