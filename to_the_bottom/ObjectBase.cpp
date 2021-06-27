#include "ObjectBase.hpp"

kp::ObjectBase::ObjectBase()
	: m_window(nullptr),
	m_event(nullptr)
{
}

void kp::ObjectBase::setWindow(sf::RenderWindow& window)
{
	m_window = &window;
}

void kp::ObjectBase::setEvent(sf::Event& event)
{
	m_event = &event;
}

sf::RenderWindow* kp::ObjectBase::getWindow()
{
	return m_window;
}

sf::Event* kp::ObjectBase::getEvent()
{
	return m_event;
}

kp::ObjectBase::~ObjectBase()
{
	m_window = nullptr;
	m_event = nullptr;
}