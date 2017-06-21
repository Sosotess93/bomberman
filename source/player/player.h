#ifndef _PLAYER_HPP_
#define _PLAYER_HPP_

#include<iostream>
#include "common.hpp"
#include "irrlicht.h"
#include "myEventManager.hpp"
//#include "eventReceiver.hpp"

namespace game
{
	struct characteristique
	{
		explicit characteristique() {}
		explicit characteristique(int hp, int power) :
			m_hp(hp),
			m_power(power){}

		characteristique& operator=(const characteristique& c)
		{
			m_hp = c.m_hp;
			m_power = c.m_power;
			return *this;
		}

		int	m_hp;
		int m_power;
	};
	typedef characteristique characteristique;


	class player
	{
	public:
		explicit player();
		explicit player(int hp, int power, float x, float y, float z);
		virtual ~player();

		void showStats() const;

		int	getHp() const;
		int getPower() const;
		common::Location<float> getLocation() const;
		irr::scene::IAnimatedMeshSceneNode* getMesh();

		void setHp(int hp);
		void setPower(int power);
		void setState(common::STATE s);
		void setLocation(const common::Location<float>& NewLocation);
		void setCharacteristic(characteristique c);

		bool putBomb();
		void setMesh(irr::scene::IAnimatedMeshSceneNode* mesh);
		//		bool event(const eventReceiver::inputCase& input);
		bool isMove(myEventManager *e);
	private:
		characteristique						m_characteristique;
		common::Location<float>					m_location;
		common::STATE							m_state;
		irr::scene::IAnimatedMeshSceneNode*		m_mesh;
	};

}
#endif // !_PLAYER_HPP_
