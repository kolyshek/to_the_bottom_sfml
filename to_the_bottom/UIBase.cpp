#include "UIBase.hpp"

kp::UIBase::UIBase()
	: m_selected(false),
	m_unicodeMaxCode(128),
	m_timer(nullptr)
{
}

void kp::UIBase::setSelected(bool selected)
{
	m_selected = selected;
}

void kp::UIBase::setUnicodeMaxCode(unsigned int unicodeMaxCode)
{
	m_unicodeMaxCode = unicodeMaxCode;
}

void kp::UIBase::setTimer(kp::Timer& timer)
{
	m_timer = &timer;
}

bool kp::UIBase::getSelected()
{
	return m_selected;
}

unsigned int kp::UIBase::getUnicodeMaxCode()
{
	return m_unicodeMaxCode;
}

kp::Timer* kp::UIBase::getTimer()
{
	return m_timer;
}

kp::UIBase::~UIBase()
{
	delete m_timer;

	m_timer = nullptr;
}