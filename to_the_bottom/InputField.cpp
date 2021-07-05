#include <iostream>

#include "InputField.hpp"

#include "Timer.hpp"

void kp::InputField::changeTextPositionToInputArea()
{
	if (m_inputArea != nullptr && m_defaultText != nullptr && m_playerText != nullptr)
	{
		sf::Vector2f newPosition(
			m_inputArea->getPosition().x - m_inputArea->getSize().x / 2.0f + m_edgeIndent->x,
			m_inputArea->getPosition().y - m_inputArea->getSize().y + 2.0f + m_edgeIndent->y);

		m_defaultText->setPosition(newPosition);
		m_playerText->setPosition(newPosition);
	}
}

void kp::InputField::changeUIStatus()
{
	if (m_window != nullptr && m_timer != nullptr)
	{
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && m_timer->isOver())
		{
			sf::Vector2f mousePosition(static_cast<float>(sf::Mouse::getPosition(*m_window).x), static_cast<float>(sf::Mouse::getPosition(*m_window).y));

			if (m_inputArea->getGlobalBounds().contains(mousePosition))
			{
				m_selected = true;
			}
			else
			{
				m_selected = false;
			}
		}
	}
}

void kp::InputField::changeMarkerValue()
{
	m_markerPositionBuffer = m_markerPosition;

	if (m_playerInput != nullptr)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left) && m_timer->isOver())
		{
			if (m_playerInput->isEmpty() != true && m_markerPosition > 0)
			{
				--m_markerPosition;
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right) && m_timer->isOver())
		{
			if (m_playerInput->isEmpty() != true && m_markerPosition < m_playerInput->getSize())
			{
				++m_markerPosition;
			}
		}
	}
}

void kp::InputField::changeMarkerPosition()
{
	if (m_playerInput != nullptr && m_playerText != nullptr)
	{
	}
}

void kp::InputField::changeFieldColors()
{
	if (m_stateColors != nullptr && m_playerText != nullptr)
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
	if (m_timer != nullptr && m_playerText != nullptr && m_playerInput != nullptr)
	{
		if (m_playerInput->getSize() < m_maxLength && m_timer->isOver())
		{
			m_playerInput->insert(m_markerPosition, m_event->text.unicode);
			m_playerText->setString(*m_playerInput);

			if (m_markerPosition < m_playerInput->getSize())
			{
				++m_markerPosition;
			}
		}
	}
}

void kp::InputField::eraseText()
{
	if (m_timer != nullptr && m_playerText != nullptr && m_playerInput != nullptr)
	{
		if (!m_playerInput->isEmpty() && m_timer->isOver())
		{
			if (m_markerPosition > 0)
			{
				m_playerInput->erase(m_markerPosition - 1);
				m_playerText->setString(*m_playerInput);

				--m_markerPosition;
			}
		}
	}
}

void kp::InputField::changeText()
{
	if (m_selected == true)
	{
		if (m_event != nullptr)
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
	m_stateColors(nullptr),
	m_edgeIndent(nullptr),
	m_markerPosition(0)
{
}

kp::InputField::InputField(const InputField& copy)
{
	m_selected = copy.m_selected;
	m_unicodeMaxCode = copy.m_unicodeMaxCode;
	*m_timer = *copy.m_timer;

	*m_inputArea = *copy.m_inputArea;
	*m_playerInput = *copy.m_playerInput;
	*m_font = *copy.m_font;
	*m_defaultText = *copy.m_defaultText;
	*m_playerText = *copy.m_playerText;
	m_maxLength = copy.m_maxLength;
	*m_stateColors = *copy.m_stateColors;
	*m_edgeIndent = *copy.m_edgeIndent;
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

void kp::InputField::setEdgeIndent(sf::Vector2f& edgeIndent)
{
	m_edgeIndent = &edgeIndent;
}

void kp::InputField::setMarkerPosition(std::size_t markerPosition)
{
	m_markerPosition = markerPosition;
	m_markerPositionBuffer = m_markerPosition;
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

sf::Vector2f* kp::InputField::getEdgeIndent()
{
	return m_edgeIndent;
}

std::size_t kp::InputField::getMarkerPosition()
{
	return m_markerPosition;
}

void kp::InputField::render()
{
	if (m_window != nullptr && m_inputArea != nullptr)
	{
		m_window->draw(*m_inputArea);
	}

	if (m_window != nullptr && m_playerText != nullptr && m_playerInput != nullptr && m_defaultText != nullptr)
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

	changeTextPositionToInputArea();
	changeUIStatus();
	changeMarkerValue();
	changeMarkerPosition();
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
	delete m_edgeIndent;

	m_inputArea = nullptr;
	m_playerInput = nullptr;
	m_font = nullptr;
	m_defaultText = nullptr;
	m_playerText = nullptr;
	m_stateColors = nullptr;
	m_edgeIndent = nullptr;
}