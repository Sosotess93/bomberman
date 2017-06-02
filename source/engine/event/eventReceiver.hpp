//
// eventReceiver.hpp for  in /home/sofiane/Documents/bomberman/engine/Event
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue May 30 21:40:04 2017 sofiane
// Last update Fri Jun  2 21:32:35 2017 sofiane
//

#ifndef	_EVENTRECEIVER_HPP_
# define _EVENTRECEIVER_HPP_

#include "irrlicht.h"

class  eventReceiver : public irr::IEventReceiver
{
  enum	inputCase
    {
      KEY_KEY_W,
      KEY_KEY_S,
      KEY_KEY_A,
      KEY_KEY_D,
      KEY_KEY_X,
      NOT_FOUND
  };

public:
  eventReceiver(irr::scene::IAnimatedMeshSceneNode *node);
  ~eventReceiver();
  virtual	bool OnEvent(const irr::SEvent &event);
};


#endif /* !_EVENTRECEIVER_HPP_ */
