#include "Timer.hpp"

kp::Timer::Timer()
	: m_timeToStop(0.0f),
	m_timeBuffer(0.0f),
	m_run(false)
{
}

void kp::Timer::setTimeToStop(float timeToStop)
{
	m_timeToStop = timeToStop;
	m_timeBuffer = m_timeToStop;
}

void kp::Timer::setTimerStatus(bool timerStatus)
{
	m_run = timerStatus;
}

float kp::Timer::getTimeToStop()
{
	return m_timeToStop;
}

bool kp::Timer::getTimerStatus()
{
	return m_run;
}

bool kp::Timer::timeIsOver()
{
	if (m_timeToStop <= 0.0f)
	{
		m_timeToStop = m_timeBuffer;

		return true;
	}
	else
	{
		return false;
	}
}

void kp::Timer::update(float m_dT)
{
	m_timeToStop -= m_dT;
}

kp::Timer::~Timer()
{
}