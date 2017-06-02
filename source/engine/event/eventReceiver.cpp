//
// eventReceiver.cpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:39:51 2017 sofiane
// Last update Fri Jun  2 22:11:08 2017 sofiane
//

#include "eventReceiver.hpp"
#include <iostream>

eventReceiver::eventReceiver(irr::scene::IAnimatedMeshSceneNode *node)
{

}

eventReceiver::~eventReceiver()
{
}

bool		eventReceiver::OnEvent(const irr::SEvent &event)
{
  inputCase	input;
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
    {
      switch (event.KeyInput.Key)
	{
	case irr::KEY_KEY_W: // avancer
	  //	  input = 1;
	  std::cout << "Vous avez appuyez sur AVANCER {W}!" << std::endl;
	  return true;
	case irr::KEY_KEY_S: // reculer
	  // input = 2;
	  std::cout << "Vous avez appuyez sur RECULER {S} !" << std::endl;
	  return true;
	case irr::KEY_KEY_A: // gauche
	  //input = 3;
	  std::cout << "Vous avez appuyez sur GAUCHE {A} !" << std::endl;
	  return true;

	case irr::KEY_KEY_D: // droite
	  //input = 4;
	  std::cout << "Vous avez appuyez sur DROITE {D} !" << std::endl;
	  return true;
	case irr::KEY_KEY_X: // pauser une bombe
	  //input = 5;
	  std::cout << "Vous avez poser une bombe {X} !" << std::endl;
	  return true;
	default:
	  //input = 6;
	  break;
	}
    }
  return false;
}
