#include "InputField.hpp"

#include "UIBase.hpp"

void kp::InputField::changeFieldColors()
{
}

void kp::InputField::insertText()
{
	if (m_playerText->getString().getSize() <= m_maxLength)
	{
		m_playerInput->insert(m_playerInput->getSize(), m_event->text.unicode);
		m_playerText->setString(*m_playerInput + "_");
	}
}

void kp::InputField::eraseText()
{
	if (!m_playerInput->isEmpty())
	{
		m_playerInput->erase(m_playerInput->getSize() - 1);
		m_playerText->setString(*m_playerInput + "_");
	}
}

void kp::InputField::changeText()
{
	if (m_selected != false)
	{
		if (m_event != nullptr && m_playerText != nullptr && m_playerInput != nullptr)
		{
			if (m_event->type == sf::Event::TextEntered
				&& m_event->text.unicode != DELETE_KEY && m_event->text.unicode != ENTER_KEY && m_event->text.unicode != ESCAPE_KEY
				&& m_event->text.unicode < m_unicodeMaxCode)
			{
				insertText();
			}

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Backspace)
				&& m_event->text.unicode < m_unicodeMaxCode)
			{
				eraseText();
			}
		}
	}
}

kp::InputField::InputField()
	: m_inputArea(nullptr),
	m_defaultText(nullptr), m_playerInput(nullptr),
	m_font(nullptr), m_playerText(nullptr)
{
	m_maxLength = 32;
	m_selected = true;
}

kp::InputField::InputField(const InputField& copy)
{
	m_selected = copy.m_selected;

	*m_inputArea = *copy.m_inputArea;
	*m_defaultText = *copy.m_defaultText;
	*m_playerInput = *copy.m_playerInput;
	*m_font = *copy.m_font;
	*m_playerText = *copy.m_playerText;
}

void kp::InputField::setInputArea(sf::RectangleShape& inputArea)
{
	m_inputArea = &inputArea;
}

void kp::InputField::setPlayerInput(sf::String& playerInput)
{
	m_playerInput = &playerInput;
}

void kp::InputField::setFont(sf::Font& font)
{
	m_font = &font;
}

void kp::InputField::setDefaultText(sf::Text& defaultText)
{
	m_defaultText = &defaultText;
}

void kp::InputField::setPlayerText(sf::Text& playerText)
{
	m_playerText = &playerText;
}

void kp::InputField::setMaxLength(sf::Uint16 maxLength)
{
	m_maxLength = maxLength;
}

sf::RectangleShape* kp::InputField::getInputArea()
{
	return m_inputArea;
}

sf::String* kp::InputField::getPlayerInput()
{
	return m_playerInput;
}

sf::Font* kp::InputField::getFont()
{
	return m_font;
}

sf::Text* kp::InputField::getDefaultText()
{
	return m_defaultText;
}

sf::Text* kp::InputField::getPlayerText()
{
	return m_playerText;
}

sf::Uint16 kp::InputField::getMaxLength()
{
	return m_maxLength;
}

void kp::InputField::render()
{
	if (m_inputArea != nullptr)
	{
		m_window->draw(*m_inputArea);
	}

	if (m_playerText != nullptr && m_playerInput != nullptr && m_defaultText != nullptr)
	{
		if (m_playerInput->isEmpty())
		{
			m_window->draw(*m_defaultText);
		}
		else
		{
			m_window->draw(*m_playerText);
		}
	}
}

void kp::InputField::update()
{
	changeFieldColors();
	changeText();
}

kp::InputField::~InputField()
{
	delete m_inputArea;
	delete m_playerInput;
	delete m_font;
	delete m_defaultText;
	delete m_playerText;

	m_inputArea = nullptr;
	m_playerInput = nullptr;
	m_font = nullptr;
	m_defaultText = nullptr;
	m_playerText = nullptr;
}