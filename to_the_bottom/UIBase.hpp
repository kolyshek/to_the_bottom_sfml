#ifndef UI_BASE
#define UI_BASE

#include "ObjectBase.hpp"

namespace kp
{
	class Timer;

	class UIBase
		: public kp::ObjectBase
	{
	protected:
		bool m_selected;
		unsigned int m_unicodeMaxCode;

		kp::Timer* m_timer;
	public:
		UIBase();

		void setSelected(bool selected);
		void setUnicodeMaxCode(unsigned int unicodeMaxCode);
		void setTimer(kp::Timer& timer);

		bool getSelected();
		unsigned int getUnicodeMaxCode();
		kp::Timer* getTimer();

		~UIBase();
	};
}

#endif // !UI_BASE