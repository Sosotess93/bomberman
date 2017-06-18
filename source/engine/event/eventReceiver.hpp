//
// eventReceiver.hpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:40:04 2017 sofiane
// Last update Sun Jun 18 18:03:56 2017 Melliti
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
      NOT_FOUND,
  };

  eventReceiver(irr::scene::IAnimatedMeshSceneNode *node);
  ~eventReceiver();
  virtual	bool OnEvent(const irr::SEvent &event);
  int		lastPressedKey;
  inputCase	lastKey();
};


#endif /* !_EVENTRECEIVER_HPP_ */
