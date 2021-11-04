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

kp::DateTime* kp::GeneralFactory::createDateTime()
{
	kp::DateTime* dateTime = new kp::DateTime;
	return dateTime;
}

kp::Palette* kp::GeneralFactory::createPalette()
{
	kp::Palette* palette = new kp::Palette;
	return palette;
}

kp::StateBase* kp::GeneralFactory::createStateBase()
{
	kp::StateBase* stateBase = new kp::StateBase;
	return stateBase;
}