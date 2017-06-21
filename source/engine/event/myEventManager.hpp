//
// eventmanager.hpp for  in /home/sofiane/Documents/bomberman/source/engine/test
//
// Made by sofiane
// Login   <sofiane@epitech.net>
//
// Started on  Tue Jun 20 23:08:10 2017 sofiane
// Last update Wed Jun 21 02:36:38 2017 sofiane
//

#ifndef _MYEVENTMANAGER_HPP_
# define _MYEVENTRECEIVER_HPP_

#include <irrlicht.h>


class	myEventManager : public irr::IEventReceiver
{
public:

  virtual bool OnEvent(const irr::SEvent& event);

  virtual bool IsKeyDown(irr::EKEY_CODE keyCode) const;

  myEventManager();
private:

  enum  inputCase
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

  bool KeyIsDown[irr::KEY_KEY_CODES_COUNT];

};

#endif /* !_MYEVENTMANAGER_HPP_ */
