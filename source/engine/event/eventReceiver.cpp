//
// eventReceiver.cpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:39:51 2017 sofiane
// Last update Sun Jun 18 20:54:53 2017 Melliti
//

#include "eventReceiver.hpp"
#include <iostream>

eventReceiver::eventReceiver()
{

}

eventReceiver::~eventReceiver()
{
}

eventReceiver::inputCase	eventReceiver::lastKey(){
  if (lastPressedKey == eventReceiver::inputCase::KEY_KEY_W){
    std::cout << "Vous avez appuyez sur AVANCER {W}!" << std::endl;
    return (lastPressedKey);
  }
  if (lastPressedKey == eventReceiver::inputCase::KEY_KEY_A){
    std::cout << "Vous avez appuyez sur GAUCHE {A} !" << std::endl;
    return (lastPressedKey);
  }
  if (lastPressedKey == eventReceiver::inputCase::KEY_KEY_S){
    std::cout << "Vous avez appuyez sur RECULER {S} !" << std::endl;
    return (lastPressedKey);
  }
  if (lastPressedKey == eventReceiver::inputCase::KEY_KEY_D){
    std::cout << "Vous avez appuyez sur DROITE {D} !" << std::endl;
    return (lastPressedKey);
  }
  if (lastPressedKey == eventReceiver::inputCase::KEY_KEY_X){
    std::cout << "Vous avez poser une bombe {X} !" << std::endl;
    return (lastPressedKey);
  }
  return (lastPressedKey);
}

bool		eventReceiver::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
    {
      switch (event.KeyInput.Key)
	{
	case eventReceiver::inputCase::KEY_KEY_W: // avancer
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_W;
	  //	  lastKey();
	  return true;
	case irr::KEY_KEY_S: // reculer
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_S;
	  //	  lastKey();
	  return true;
	case irr::KEY_KEY_A: // gauche
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_A;
	  //	  lastKey();
	  return true;
	case irr::KEY_KEY_D: // droite
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_D;
	  //	  lastKey();
	  return true;
	case irr::KEY_KEY_X: // pauser une bombe
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_X;
	  //	  lastKey();
	  return true;
	default:
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::NOT_FOUND;
	  break;
	}
    }
  return (false);
}
