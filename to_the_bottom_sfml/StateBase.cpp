#include "StateBase.hpp"

kp::StateBase::StateBase()
{
}

void kp::StateBase::setEvent(sf::Event* event)
{
	m_event = event;
}

const sf::Event* kp::StateBase::getEvent() const
{
	return m_event;
}

kp::StateBase::~StateBase()
{
}