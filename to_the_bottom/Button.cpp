#include "Button.hpp"

kp::Button::Button()
	: m_buttonArea(nullptr),
	m_buttonText(nullptr)
{
}

kp::Button::Button(Button& copy)
{
	m_selected = copy.m_selected;

	*m_buttonArea = *copy.m_buttonArea;
	*m_buttonText = *copy.m_buttonText;
}

void kp::Button::setButtonArea(sf::RectangleShape& buttonArea)
{
	m_buttonArea = &buttonArea;
}

void kp::Button::setButtonText(sf::Text& buttonText)
{
	m_buttonText = &buttonText;
}

sf::RectangleShape* kp::Button::getButtonArea()
{
	return m_buttonArea;
}

sf::Text* kp::Button::getButtonText()
{
	return m_buttonText;
}

void kp::Button::render()
{
}

void kp::Button::update(float dT)
{
	m_dT = dT;
}

kp::Button::~Button()
{
	delete m_buttonArea;
	delete m_buttonText;

	m_buttonArea = nullptr;
	m_buttonText = nullptr;
}