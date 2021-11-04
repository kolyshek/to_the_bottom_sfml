#ifndef GENERAL_FACTORY_HPP
#define GENERAL_FACTORY_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class ObjectBase;
	class Timer;
	class DateTime;
	class Palette;
	class StateBase;

	class GeneralFactory
	{
	public:
		static kp::ObjectBase* createObjectBase();
		static kp::Timer* createTimer();
		static kp::DateTime* createDateTime();
		static kp::Palette* createPalette();
		static kp::StateBase* createStateBase();
	};
}

#endif // !GENERAL_FACTORY_HPP