#ifndef _COMMON_HPP_
#define _COMMON_HPP_

namespace common
{
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

		T m_x;
		T m_y;
		T m_z;
	};
}


#endif // !_COMMON_HPP_
