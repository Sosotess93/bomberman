//
// eventReceiver.hpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:40:04 2017 sofiane
// Last update Tue Jun 20 14:00:34 2017 sofiane
//

#ifndef	_EVENTRECEIVER_HPP_
# define _EVENTRECEIVER_HPP_

#include "irrlicht.h"

class  eventReceiver : public irr::IEventReceiver
{
public:
  enum	inputCase
    {
      KEY_KEY_W = irr::KEY_KEY_W,
      KEY_KEY_S = irr::KEY_KEY_S,
      KEY_KEY_A = irr::KEY_KEY_A,
      KEY_KEY_D = irr::KEY_KEY_D,
      KEY_KEY_X = irr::KEY_KEY_X,
      KEY_DOWN = irr::KEY_DOWN,
      KEY_UP = irr::KEY_UP,
      KEY_LEFT = irr::KEY_LEFT,
      KEY_RIGHT = irr::KEY_RIGHT,
      NOT_FOUND,
    };
  inputCase	lastPressedKey;
  inputCase	lastKey();
  eventReceiver();
  ~eventReceiver();
  virtual	bool OnEvent(const irr::SEvent &event);
};


#endif /* !_EVENTRECEIVER_HPP_ */
