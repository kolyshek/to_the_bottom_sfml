#include "InputField.hpp"
#include "Timer.hpp"

void kp::InputField::initOfBaseTypes()
{
	m_size = 32;
}

void kp::InputField::initRect()
{
	m_inputRect = new sf::RectangleShape;
	m_inputRect->setSize(sf::Vector2f(15 * m_size, 20));
	m_inputRect->setFillColor(sf::Color::White);
	m_inputRect->setOutlineThickness(2);
	m_inputRect->setOutlineColor(sf::Color(127, 127, 127));
	m_inputRect->setPosition(sf::Vector2f(0.0f, 0.0f));
}

void kp::InputField::initFont()
{
	m_font->loadFromFile(".../fonts/pixel_letters_full.ttf");
}

void kp::InputField::initText()
{
	m_text = new sf::String;
}

kp::InputField::InputField()
{
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
	*m_text = *copy.m_text;
	m_active = copy.m_active;
}

bool kp::InputField::contains(sf::Vector2f point) const
{
	return m_inputRect->getGlobalBounds().contains(point);
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

	if (m_event->text.unicode == 8) {
		*m_text = m_text->substring(0, m_text->getSize() - 1);
	}
	else if (m_text->getSize() < m_size) {
		m_text += m_event->text.unicode;
	}
}

void kp::InputField::setPosition(sf::Vector2f position)
{
	m_inputRect->setPosition(position);
}

const sf::Vector2f kp::InputField::getPosition() const
{
	return m_inputRect->getPosition();
}

void kp::InputField::setText(sf::String& text)
{
	m_text = &text;
}

const sf::String* kp::InputField::getText() const
{
	return m_text;
}

void kp::InputField::render()
{
	m_window->draw(*m_inputRect);
}

void kp::InputField::update(float dT)
{
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
	delete m_text;
}