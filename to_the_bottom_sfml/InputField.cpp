#include "InputField.hpp"

void kp::InputField::memoryAllocation()
{
	m_inputRect = new sf::RectangleShape;
	m_font = new sf::Font;
	m_string = new sf::String;
	m_text = new sf::Text;
}

void kp::InputField::initOfBaseTypes()
{
	m_size = 16;
}

void kp::InputField::initRect()
{
	m_inputRect->setSize(sf::Vector2f(m_size * 8, 20));
	m_inputRect->setFillColor(sf::Color(170, 170, 170));
	m_inputRect->setOutlineThickness(2);
	m_inputRect->setOutlineColor(sf::Color(70, 70, 70));
	m_inputRect->setOrigin(sf::Vector2f(0.0f, 0.0f));
	m_inputRect->setPosition(sf::Vector2f(0.0f, 0.0f));
}

void kp::InputField::initFont()
{
	m_font->loadFromFile("fonts/gameplay.ttf");
}

void kp::InputField::initText()
{
	m_text->setCharacterSize(16);
	m_text->setFillColor(sf::Color(40, 40, 40));
	m_text->setOrigin(sf::Vector2f(-2.0f, -2.0f));
	m_text->setPosition(sf::Vector2f(0.0f, 0.0f));
	m_text->setFont(*m_font);
}

kp::InputField::InputField()
{
	memoryAllocation();
	initOfBaseTypes();
	initRect();
	initFont();
	initText();
}

kp::InputField::InputField(const InputField& copy)
{
	*m_inputRect = *copy.m_inputRect;
	m_size = copy.m_size;
	*m_font = *copy.m_font;
	*m_string = *copy.m_string;
	m_active = copy.m_active;
}

void kp::InputField::setWindow(sf::RenderWindow* window)
{
	m_window = window;
}

const sf::RenderWindow* kp::InputField::getWindow() const
{
	return m_window;
}

void kp::InputField::setEvent(sf::Event* event)
{
	m_event = event;
}

const sf::Event* kp::InputField::getEvent() const
{
	return m_event;
}

void kp::InputField::checkInput()
{
	if (!m_active || m_event->type != sf::Event::TextEntered)
		return;

	if (m_event->text.unicode == 8)
	{
		*m_string = m_string->substring(0, m_string->getSize() - 1);
	}
	else if (m_string->getSize() < m_size)
	{
		*m_string += m_event->text.unicode;
	}

	m_text->setString(*m_string);
}

void kp::InputField::checkMouseContains()
{
	if (m_event->type != sf::Event::MouseButtonPressed)
		return;

	sf::Vector2f position(sf::Mouse::getPosition().x, sf::Mouse::getPosition().y);

	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)
		&& m_inputRect->getGlobalBounds().contains(position))
	{
		if (m_active != true)
			m_active = true;
		else
			m_active = false;
	}
}

void kp::InputField::setPosition(sf::Vector2f position)
{
	m_inputRect->setPosition(position);
	m_text->setPosition(position);
}

const sf::Vector2f kp::InputField::getPosition() const
{
	return m_inputRect->getPosition();
}

void kp::InputField::setText(sf::String& string)
{
	m_string = &string;
	m_text->setString(string);
}

const sf::String* kp::InputField::getText() const
{
	return m_string;
}

void kp::InputField::render()
{
	m_window->draw(*m_inputRect);
	m_window->draw(*m_text);
}

void kp::InputField::update(float dT)
{
	checkMouseContains();

	if (m_active)
	{
		m_dT = dT;
		checkInput();
	}
}

kp::InputField::~InputField()
{
	delete m_inputRect;
	delete m_font;
	delete m_string;
	delete m_text;
}