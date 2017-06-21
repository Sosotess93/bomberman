//
// eventmanager.cpp for  in /home/sofiane/Documents/bomberman/source/engine/test
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue Jun 20 23:24:25 2017 sofiane
// Last update Wed Jun 21 13:36:44 2017 sofiane
//

#include "myEventManager.hpp"
#include <iostream>

bool	myEventManager::OnEvent(const irr::SEvent& event)
{
  if (event.EventType == irr::EET_KEY_INPUT_EVENT)
    KeyIsDown[event.KeyInput.Key] = event.KeyInput.PressedDown;
  return (false);
}

bool	myEventManager::IsKeyDown(irr::EKEY_CODE keyCode) const
{
  return KeyIsDown[keyCode];
}

myEventManager::myEventManager()
{
  irr::u32 i;

  i = 0;
  while (i< irr::KEY_KEY_CODES_COUNT)
    {
      KeyIsDown[i] = false;
      i++;
    }
}
