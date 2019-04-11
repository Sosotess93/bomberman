//
// eventReceiver.cpp for indie in /home/sivaku_v/rendu/Bomberman
// 
// Made by Vituzan Sivakumaran
// Login   <sivaku_v@epitech.net>
// 
// Started on  Sun Jun  5 18:11:58 2016 Vituzan Sivakumaran
// Last update Sun Jun  5 21:38:37 2016 Vituzan Sivakumaran
//

#include "eventReceiver.hpp"

EventReceiver::EventReceiver(Perso **perso)
{
  perso1 = perso[0]->_perso;
  if (perso[1])
    perso2 = perso[1]->_perso;
  _1animRun = true;
  _1isMoving_up = false;
  _1isMoving_down = false;
  _1isMoving_left = false;
  _1isMoving_right = false;
  _1bombe_posed = false;
  _2animRun = true;
  _2isMoving_up = false;
  _2isMoving_down = false;
  _2isMoving_left = false;
  _2isMoving_right = false;
  _2bombe_posed = false;
}

int	EventReceiver::first_perso(const irr::SEvent &event)
{
  if (event.KeyInput.Key == irr::KEY_KEY_W)
    _1isMoving_up = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_S)
    _1isMoving_down = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_A)
    _1isMoving_left = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_D)
    _1isMoving_right = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_X)
    _1bombe_posed = (event.KeyInput.PressedDown == true) ? true : false;
  return (true);
}

int	EventReceiver::second_perso(const irr::SEvent &event)
{
  if (event.KeyInput.Key == irr::KEY_KEY_U)
    _2isMoving_up = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_J)
    _2isMoving_down = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_H)
    _2isMoving_left = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_K)
    _2isMoving_right = (event.KeyInput.PressedDown == true) ? true : false;
  else if (event.KeyInput.Key == irr::KEY_KEY_M)
    _2bombe_posed = (event.KeyInput.PressedDown == true) ? true : false;
  return (true);
}

bool EventReceiver::OnEvent(const irr::SEvent &event)
{
  if ((event.EventType == irr::EET_KEY_INPUT_EVENT) &&
      ((event.KeyInput.Key == irr::KEY_KEY_W) ||
       (event.KeyInput.Key == irr::KEY_KEY_S) ||
       (event.KeyInput.Key == irr::KEY_KEY_A) ||
       (event.KeyInput.Key == irr::KEY_KEY_D) ||
       (event.KeyInput.Key == irr::KEY_KEY_X)))
    {
      first_perso(event);
    }
  else if ((event.EventType == irr::EET_KEY_INPUT_EVENT) &&
      ((event.KeyInput.Key == irr::KEY_KEY_U) ||
       (event.KeyInput.Key == irr::KEY_KEY_J) ||
       (event.KeyInput.Key == irr::KEY_KEY_H) ||
       (event.KeyInput.Key == irr::KEY_KEY_K) ||
       (event.KeyInput.Key == irr::KEY_KEY_M)))
    {
      second_perso(event);
    }
  else
    return (false);
}

void EventReceiver::majPosMesh1()
{
  irr::core::vector3df v = perso1->getPosition();
  irr::core::vector3df r = perso1->getRotation();

  if (perso1 != 0 && _1isMoving_up == true)
    {
      v.X += 1.0f;
      r.Y = 0.0f;
    }
  else if (perso1 != 0 && _1isMoving_down == true)
    {
      v.X -= 1.0f;
      r.Y = 175.0f;
    }
  else if (perso1 != 0 && _1isMoving_left == true)
    {
      v.Z += 1.0f;
      r.Y = -87.0f;
    }
  else if (perso1 != 0 && _1isMoving_right == true)
    {
      v.Z -= 1.0f;
      r.Y = 87.0f;
    }
  perso1->setPosition(v);
  perso1->setRotation(r);
  majAnimMeshUp1();
}

void EventReceiver::majPosMesh2()
{
  if (perso2 != 0)
    {
      irr::core::vector3df v = perso2->getPosition();
      irr::core::vector3df r = perso2->getRotation();

      if (_2isMoving_up == true)
	{
	  v.X += 1.0f;
	  r.Y = 0.0f;
	}
      else if (_2isMoving_down == true)
	{
	  v.X -= 1.0f;
	  r.Y = 175.0f;
	}
      else if (_2isMoving_left == true)
	{
	  v.Z += 1.0f;
	  r.Y = -87.0f;
	}
      else if (_2isMoving_right == true)
	{
	  v.Z -= 1.0f;
	  r.Y = 87.0f;
	}
      perso2->setPosition(v);
      perso2->setRotation(r);
      majAnimMeshUp2();
    }
}

int	EventReceiver::is_1_pressed() const
{
  if (_1isMoving_up || _1isMoving_down || _1isMoving_left || _1isMoving_right)
    return (1);
  return (0);
}
int	EventReceiver::is_2_pressed() const
{
  if (_2isMoving_up || _2isMoving_down || _2isMoving_left || _2isMoving_right)
    return (1);
  return (0);
}

void	EventReceiver::majAnimMeshUp1()
{
  if (!is_1_pressed() && _1animRun == true)
    {
      perso1->setMD2Animation(irr::scene::EMAT_STAND);
      perso1->setFrameLoop(1,44);
      perso1->setAnimationSpeed(80);
      _1animRun = false;
    }
  if (perso1 != 0 && is_1_pressed() && _1animRun == false)
    {
      perso1->setMD2Animation(irr::scene::EMAT_RUN);
      _1animRun = true;
    }
}

void	EventReceiver::majAnimMeshUp2()
{
  if (perso2 != 0 && !is_2_pressed() && _2animRun == true)
    {
      perso2->setMD2Animation(irr::scene::EMAT_STAND);
      perso2->setFrameLoop(1,44);
      perso2->setAnimationSpeed(80);
      _2animRun = false;
    }
  if (perso2 != 0 && is_2_pressed() && _2animRun == false)
    {
      perso2->setMD2Animation(irr::scene::EMAT_RUN);
      _2animRun = true;
    }
}

void	EventReceiver::majBomb(Game *bomberman)
{
  if (this->_1bombe_posed)
    {
      Bomb bomb(bomberman, bomberman->_perso[0]);
      _1bombe_posed = false;
    }
  if (this->_2bombe_posed)
    {
      Bomb bomb(bomberman, bomberman->_perso[1]);
      _2bombe_posed = false;
    }
}
