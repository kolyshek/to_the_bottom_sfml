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

		void setTimer(kp::Timer& timer);
		void setSelected(bool selected);
		void setUnicodeMaxCode(unsigned int unicodeMaxCode);

		kp::Timer* getTimer();
		bool getSelected();
		unsigned int getUnicodeMaxCode();

		~UIBase();
	};
}

#endif // !UI_BASE