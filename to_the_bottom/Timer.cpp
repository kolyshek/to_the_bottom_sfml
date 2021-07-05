#include "Timer.hpp"

kp::Timer::Timer()
	: m_begin(0.0f), m_end(0.0f),
	m_beginBuffer(0.0f), m_endBuffer(0.0f),
	m_run(false),
	m_direction(kp::TimeDirection::UNKNOWN)
{
}

void kp::Timer::setBegin(float begin)
{
	m_begin = begin;
	m_beginBuffer = m_begin;
}

void kp::Timer::setEnd(float end)
{
	m_end = end;
	m_endBuffer = m_end;
}

void kp::Timer::setTimerRun(bool timerRun)
{
	m_run = timerRun;
}

void kp::Timer::setDirection(kp::TimeDirection direction)
{
	m_direction = direction;
}

float kp::Timer::getBegin()
{
	return m_beginBuffer;
}

float kp::Timer::getEnd()
{
	return m_endBuffer;
}

bool kp::Timer::getTimerRun()
{
	return m_run;
}

kp::TimeDirection kp::Timer::getDirection()
{
	return m_direction;
}

bool kp::Timer::isOver()
{
	if (m_direction == kp::TimeDirection::INCREASE)
	{
		if (m_begin >= m_end)
		{
			m_begin = m_beginBuffer;

			return true;
		}
	}
	else if (m_direction == kp::TimeDirection::DECREASE)
	{
		if (m_begin <= m_end)
		{
			m_begin = m_beginBuffer;

			return true;
		}
	}
	
	return false;
}

void kp::Timer::update(float dT)
{
	if (m_run)
	{
		if (m_direction == kp::TimeDirection::INCREASE)
		{
			m_begin += dT;
		}
		else if (m_direction == kp::TimeDirection::DECREASE)
		{
			m_begin -= dT;
		}
	}
}

kp::Timer::~Timer()
{
}