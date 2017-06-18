//
// eventReceiver.cpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:39:51 2017 sofiane
// Last update Sun Jun 18 22:34:35 2017 sofiane
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
  return (lastPressedKey);
}

bool		eventReceiver::OnEvent(const irr::SEvent &event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT && !event.KeyInput.PressedDown)
    {
	  switch (event.KeyInput.Key)
	{
	case eventReceiver::inputCase::KEY_KEY_W: // avancer
	  lastPressedKey = eventReceiver::inputCase::KEY_KEY_W;
	case irr::KEY_KEY_S: // reculer
	  lastPressedKey = eventReceiver::inputCase::KEY_KEY_S;
	case irr::KEY_KEY_A: // gauche
	  lastPressedKey = eventReceiver::inputCase::KEY_KEY_A;
	case irr::KEY_KEY_D: // droite
	  lastPressedKey = eventReceiver::inputCase::KEY_KEY_D;
	case irr::KEY_KEY_X: // pauser une bombe
	  lastPressedKey = eventReceiver::inputCase::KEY_KEY_X;
	default:
	  lastPressedKey = eventReceiver::inputCase::NOT_FOUND;
	  break;
	}
	  return (true);
    }
  return (false);
}
