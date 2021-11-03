#include "Button.hpp"

void kp::Button::memoryAllocation()
{
	m_btnRect = new sf::RectangleShape;
}

void kp::Button::initRect()
{
	m_btnRect->setSize(sf::Vector2f(60, 20));
	m_btnRect->setFillColor(sf::Color(117, 117, 117));
	m_btnRect->setOutlineThickness(2);
	m_btnRect->setOutlineColor(sf::Color(127, 127, 127));
	m_btnRect->setPosition(sf::Vector2f(0.0f, 0.0f));
}

kp::Button::Button()
{
	memoryAllocation();
	initRect();
}

kp::Button::Button(Button& copy)
{
	*m_btnRect = *copy.m_btnRect;
	m_active = copy.m_active;
}

void kp::Button::render()
{
}

void kp::Button::update(float dT)
{
	if (m_active)
	{
		m_dT = dT;
	}
}

kp::Button::~Button()
{
	delete m_btnRect;
}