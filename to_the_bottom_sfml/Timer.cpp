#include "Timer.hpp"

void kp::Timer::initOfBaseTypes()
{
	m_begin = 0.0f;
	m_end = 4.0f;
	m_limitation = kp::Limitation::Limited;
}

kp::Timer::Timer()
{
	initOfBaseTypes();
}

kp::Timer::Timer(const kp::Timer& copy)
{
	m_begin = copy.m_begin;
	m_end = copy.m_end;
	m_limitation = copy.m_limitation;
}

void kp::Timer::setActive(bool active)
{
	m_active = active;
}

bool kp::Timer::isActive()
{
	return m_active;
}

void kp::Timer::setLimitation(const kp::Limitation limitation)
{
	m_limitation = limitation;
}

const kp::Limitation kp::Timer::getLimitation() const
{
	return m_limitation;
}

void kp::Timer::setLimit(float seconds)
{
	m_end = seconds;
}

const float kp::Timer::getLimit() const
{
	return m_end;
}

const bool kp::Timer::isOver() const
{
	if (m_active)
	{
		if (m_begin >= m_end
			&& m_limitation == kp::Limitation::Limited)
		{
			return true;
		}
	}

	return false;
}

void kp::Timer::reset()
{
	m_begin = 0.0f;
	m_active = false;
	m_limitation = kp::Limitation::Limited;
}

void kp::Timer::render()
{
}

void kp::Timer::update(float dT)
{
	m_dT = dT;

	if (m_active)
	{
		if (m_limitation == kp::Limitation::Unknown)
		{
			reset();
			return;
		}

		if (m_begin <= m_end
			|| m_limitation == kp::Limitation::Unlimited)
		{
			m_begin += m_dT;
		}
	}
}