#include "ObjectBase.hpp"
#include "Timer.hpp"

void kp::ObjectBase::initOfBaseTypes()
{
	m_active = false;
	m_dT = 0.0f;
}

kp::ObjectBase::ObjectBase()
{
	initOfBaseTypes();
}

void kp::ObjectBase::setActive(bool active)
{
	m_active = active;
}

bool kp::ObjectBase::isActive()
{
	return m_active;
}

void kp::ObjectBase::render()
{
}

void kp::ObjectBase::update(float dT)
{
	if (m_active)
	{
		m_dT = dT;
	}
}

kp::ObjectBase::~ObjectBase()
{
}