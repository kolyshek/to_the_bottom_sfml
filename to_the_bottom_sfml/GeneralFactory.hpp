#ifndef GENERAL_FACTORY_HPP
#define GENERAL_FACTORY_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class GeneralFactory
	{
	public:
		static kp::ObjectBase* createObjectBase();
		static kp::Timer* createTimer();
	};
}

#endif // !GENERAL_FACTORY_HPP