//
// eventReceiver.cpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:39:51 2017 sofiane
// Last update Sun Jun 18 18:40:51 2017 Melliti
//

#include "eventReceiver.hpp"
#include <iostream>

eventReceiver::eventReceiver(irr::scene::IAnimatedMeshSceneNode *node)
{

}

eventReceiver::~eventReceiver()
{
}

eventReceiver::inputCase	eventReceiver::lastKey(){
  if (eventReceiver::lastPressedKey == eventReceiver::inputCase::KEY_KEY_W){
    std::cout << "Vous avez appuyez sur AVANCER {W}!" << std::endl;
    return (eventReceiver::inputCase::KEY_KEY_W);
  }
  if (eventReceiver::lastPressedKey == eventReceiver::inputCase::KEY_KEY_A)
    return (eventReceiver::inputCase::KEY_KEY_A);
  if (eventReceiver::lastPressedKey == eventReceiver::inputCase::KEY_KEY_S)
    return (eventReceiver::inputCase::KEY_KEY_S);
  if (eventReceiver::lastPressedKey == eventReceiver::inputCase::KEY_KEY_D)
    return (eventReceiver::inputCase::KEY_KEY_D);
  if (eventReceiver::lastPressedKey == eventReceiver::inputCase::KEY_KEY_X)
    return (eventReceiver::inputCase::KEY_KEY_X);
  return (eventReceiver::inputCase::NOT_FOUND);
}

// eventReceiver::inputCase	eventReceiver::recupInput(const irr::SEvent &event)
// {
//   if (event.EventType == eventReceiver::inputCase::KEY_KEY_W)
//     return (inputCase);
// }

bool		eventReceiver::OnEvent(const irr::SEvent &event)
{
  //  inputCase	input;
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
    {
      switch (event.KeyInput.Key)
	{
	case eventReceiver::inputCase::KEY_KEY_W: // avancer
	  //input = 1;
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_W;
	  lastKey();
	  return true;
	case irr::KEY_KEY_S: // reculer
	  // input = 2;
	  std::cout << "Vous avez appuyez sur RECULER {S} !" << std::endl;
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_S;
	  return true;
	case irr::KEY_KEY_A: // gauche
	  //input = 3;
	  std::cout << "Vous avez appuyez sur GAUCHE {A} !" << std::endl;
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_A;
	  return true;

	case irr::KEY_KEY_D: // droite
	  //input = 4;
	  std::cout << "Vous avez appuyez sur DROITE {D} !" << std::endl;
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_D;
	  return true;
	case irr::KEY_KEY_X: // pauser une bombe
	  //input = 5;
	  std::cout << "Vous avez poser une bombe {X} !" << std::endl;
	  eventReceiver::lastPressedKey = eventReceiver::inputCase::KEY_KEY_X;
	  return true;
	default:

	  //input = 6;
	  break;
	}
    }
  return (false);
}
