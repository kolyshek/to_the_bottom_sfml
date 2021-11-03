#include "CheckBox.hpp"

void kp::CheckBox::memoryAllocation()
{
	m_checkRect = new sf::RectangleShape;
}

void kp::CheckBox::initRect()
{
	m_checkRect->setSize(sf::Vector2f(20, 20));
	m_checkRect->setFillColor(sf::Color(70, 70, 70));
	m_checkRect->setOutlineThickness(2);
	m_checkRect->setOutlineColor(sf::Color(127, 127, 127));
	m_checkRect->setPosition(sf::Vector2f(0.0f, 0.0f));
}

kp::CheckBox::CheckBox()
{
	memoryAllocation();
	initRect();
}

kp::CheckBox::CheckBox(const kp::CheckBox& copy)
{
	*m_checkRect = *copy.m_checkRect;
	m_active = copy.m_active;
}

bool kp::CheckBox::contains(sf::Vector2f point) const
{
	return m_checkRect->getGlobalBounds().contains(point);
}

void kp::CheckBox::setActive(bool active)
{
}

bool kp::CheckBox::isActive()
{
	return false;
}

void kp::CheckBox::render()
{
}

void kp::CheckBox::update(float dT)
{
	m_dT = dT;

	if (m_active)
	{

	}
}

kp::CheckBox::~CheckBox()
{
}