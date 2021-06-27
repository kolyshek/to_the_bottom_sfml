#ifndef UI_BASE
#define UI_BASE

#include "ObjectBase.hpp"

namespace kp
{
	class UIBase
		: public kp::ObjectBase
	{
	protected:
		bool m_selected;
		unsigned int m_unicodeMaxCode;
	public:
		UIBase();
	};
}

#endif // !UI_BASE