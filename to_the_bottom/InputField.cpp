#include "InputField.hpp"

#include "Timer.hpp"

void kp::InputField::changeUIStatus()
{
	if (m_event != nullptr && m_timer != nullptr)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_timer->timeIsOver()
			&& sf::Mouse::getPosition().x <= (m_inputArea->getPosition().x + m_inputArea->getSize().x)
			&& sf::Mouse::getPosition().x >= (m_inputArea->getPosition().x - m_inputArea->getSize().x)
			&& sf::Mouse::getPosition().y <= (m_inputArea->getPosition().y + m_inputArea->getSize().y)
			&& sf::Mouse::getPosition().y >= (m_inputArea->getPosition().y - m_inputArea->getSize().y))
		{
			m_selected = true;
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_timer->timeIsOver()
			&& sf::Mouse::getPosition().x >= (m_inputArea->getPosition().x + m_inputArea->getSize().x)
			&& sf::Mouse::getPosition().x <= (m_inputArea->getPosition().x - m_inputArea->getSize().x)
			&& sf::Mouse::getPosition().y >= (m_inputArea->getPosition().y + m_inputArea->getSize().y)
			&& sf::Mouse::getPosition().y <= (m_inputArea->getPosition().y - m_inputArea->getSize().y))
		{
			m_selected = false;
		}
	}
}

void kp::InputField::changeFieldColors()
{
	if (m_stateColors != nullptr)
	{
		if (m_selected == true)
		{
			m_inputArea->setFillColor(m_stateColors->selectedTrueInputArea);
			m_inputArea->setOutlineColor(m_stateColors->selectedTrueOutline);
			m_defaultText->setFillColor(m_stateColors->selectedTrueDefaultText);
			m_playerText->setFillColor(m_stateColors->selectedTruePlayerText);
		}
		else
		{
			m_inputArea->setFillColor(m_stateColors->selectedFalseInputArea);
			m_inputArea->setOutlineColor(m_stateColors->selectedFalseOutline);
			m_defaultText->setFillColor(m_stateColors->selectedFalseDefaultText);
			m_playerText->setFillColor(m_stateColors->selectedFalsePlayerText);
		}
	}
}

void kp::InputField::insertText()
{
	if (m_timer != nullptr)
	{
		if (m_playerText->getString().getSize() <= m_maxLength && m_timer->timeIsOver())
		{
			m_playerInput->insert(m_playerInput->getSize(), m_event->text.unicode);
			m_playerText->setString(*m_playerInput + "_");
		}
	}
}

void kp::InputField::eraseText()
{
	if (m_timer != nullptr)
	{
		if (!m_playerInput->isEmpty() && m_timer->timeIsOver())
		{
			m_playerInput->erase(m_playerInput->getSize() - 1);
			m_playerText->setString(*m_playerInput + "_");
		}
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
	m_font(nullptr), m_playerText(nullptr),
	m_maxLength(32),
	m_stateColors(nullptr)
{
	m_selected = true;
}

kp::InputField::InputField(const InputField& copy)
{
	m_selected = copy.m_selected;

	*m_inputArea = *copy.m_inputArea;
	*m_playerInput = *copy.m_playerInput;
	*m_font = *copy.m_font;
	*m_defaultText = *copy.m_defaultText;
	*m_playerText = *copy.m_playerText;
	m_maxLength = copy.m_maxLength;
	*m_timer = *copy.m_timer;
	*m_stateColors = *copy.m_stateColors;
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

void kp::InputField::setStateColors(kp::StateColors& stateColors)
{
	m_stateColors = &stateColors;
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

kp::StateColors* kp::InputField::getStateColors()
{
	return m_stateColors;
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

void kp::InputField::update(float dT)
{
	m_dT = dT;

	if (m_timer != nullptr)
	{
		m_timer->update(m_dT);
	}

	changeUIStatus();
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
	delete m_stateColors;

	m_inputArea = nullptr;
	m_playerInput = nullptr;
	m_font = nullptr;
	m_defaultText = nullptr;
	m_playerText = nullptr;
	m_stateColors = nullptr;
}