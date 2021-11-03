#include "GeneralFactory.hpp"

kp::ObjectBase* kp::GeneralFactory::createObjectBase()
{
	kp::ObjectBase* objectBase = new kp::ObjectBase;

	return objectBase;
}

kp::Timer* kp::GeneralFactory::createTimer()
{
	kp::Timer* timer = new kp::Timer;

	return timer;
}