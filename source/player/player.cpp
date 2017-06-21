#include "player.h"

namespace game
{
  player::player() :
    m_characteristique(3, 2),
    m_location(1, 1, 1),
    m_state(common::STATE::STATE_UNKNOW)
  {
  }

  player::player(int hp, int power, float x, float y, float z):
    m_characteristique(hp, power),
    m_location(x, y, z),
    m_state(common::STATE::STATE_UNKNOW)
  {
  }

  player::~player()
  {
  }

  void player::showStats() const
  {
    std::cout << "Hp: " << m_characteristique.m_hp << std::endl;
    std::cout << "Power: " << m_characteristique.m_power << std::endl;
    std::cout << "Location X: " << m_location.m_x << std::endl;
    std::cout << "Location Y: " << m_location.m_y << std::endl;
    std::cout << "Location Z: " << m_location.m_z << std::endl;
  }

  int player::getHp() const
  {
    return m_characteristique.m_hp;
  }

  int player::getPower()const
  {
    return m_characteristique.m_power;
  }

  common::Location<float> player::getLocation() const
  {
    return m_location;
  }

  irr::scene::IAnimatedMeshSceneNode* player::getMesh()
  {
    return m_mesh;
  }

  void player::setState(common::STATE s)
  {
    m_state = s;
  }


  void player::setHp(int hp)
  {
    m_characteristique.m_hp = hp;
  }

  void player::setPower(int power)
  {
    m_characteristique.m_power = power;
  }

  void player::setCharacteristic(characteristique c)
  {
    m_characteristique = c;
  }

  void player::setLocation(const common::Location<float>& NewLocation)
  {
    m_location = NewLocation;
  }

  bool player::putBomb()
  {
    if (m_characteristique.m_power <= 0)
      return false;
    m_characteristique.m_power -= 1;
    std::cout << "Put Bomb ("
	      << m_location.m_x
	      << ", "
	      << m_location.m_y
	      << ", "
	      << m_location.m_z
	      << ")"
	      << std::endl;
    return TRUE;
  }

  void player::setMesh(irr::scene::IAnimatedMeshSceneNode* mesh)
  {
    if (mesh != NULL)
      m_mesh = mesh;
  }

  bool player::event(const eventReceiver::inputCase& input)
  {
    switch (input)
      {
      case eventReceiver::inputCase::KEY_KEY_W:
	{
	  std::cout << "forward" << std::endl;
	  m_location + common::Location<float>(10, 0, 0);
	} break;
      case eventReceiver::inputCase::KEY_KEY_S:
	{
	  m_location + common::Location<float>(-10, 0, 0);
	} break;
      case eventReceiver::inputCase::KEY_KEY_D:
	{
	  m_location + common::Location<float>(0, 10, 0);
	} break;
      case eventReceiver::inputCase::KEY_KEY_A:
	{
	  m_location + common::Location<float>(0, -10, 0);
	} break;
      case eventReceiver::inputCase::KEY_KEY_X:
	{
	  m_location + common::Location<float>(0, 0, 0);
	} break;
      default:
	return false;
	break;
      }
    return true;
  }
}
