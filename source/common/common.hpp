#ifndef _COMMON_HPP_
#define _COMMON_HPP_

#if !defined(TRUE)
#define FALSE false
#endif
#if !defined(FAlSE)
#define TRUE true
#endif

namespace common
{

	enum STATE
	{
		IDLE,
		STAND,
		RUN,
		JUMP,
		PUT_BOMB,
		STATE_UNKNOW
	};

	enum ITEM
	{
		PLAYER,
		ENNEMY,
		OBSTACLE,
		BOMB,
		EXPLOSION,
		ITEM_UNKNOW
	};

	template <typename T>
	struct Location
	{
		explicit Location<T>() {}
		explicit Location<T>(T x, T y, T z):
			m_x(x),
			m_y(y),
			m_z(z)
		{}
		Location& operator=(const common::Location<T>& NewLocation)
		{
			m_x = NewLocation.m_x;
			m_y = NewLocation.m_y;
			m_z = NewLocation.m_z;
			return *this;
		}
		Location& operator+(const common::Location<T>& NewLocation)
		{
			m_x + NewLocation.m_x;
			m_y + NewLocation.m_y;
			m_z + NewLocation.m_z;
			return *this;
		}

		T m_x;
		T m_y;
		T m_z;
	};
}


#endif // !_COMMON_HPP_
