#include "UIFactory.hpp"

#include "InputField.hpp"
#include "Button.hpp"
#include "Timer.hpp"

kp::InputField* kp::UIFactory::createInputField(sf::RenderWindow& window, sf::Event& event)
{
	kp::InputField* inputField = new kp::InputField;

	inputField->setWindow(window);
	inputField->setEvent(event);

	inputField->setInputArea(*(new sf::RectangleShape));
	inputField->setPlayerInput(*(new sf::String));
	inputField->setFont(*(new sf::Font));
	inputField->setDefaultText(*(new sf::Text));
	inputField->setPlayerText(*(new sf::Text));
	inputField->setMaxLength(32);
	inputField->setTimer(*(new kp::Timer));
	inputField->setStateColors(*(new kp::StateColors));
	inputField->setEdgeIndent(*(new sf::Vector2f));

	return inputField;
}

kp::Button* kp::UIFactory::createButton(sf::RenderWindow& window, sf::Event& event)
{
	kp::Button* button = new kp::Button;

	button->setWindow(window);
	button->setEvent(event);

	button->setButtonArea(*(new sf::RectangleShape));
	button->setButtonText(*(new sf::Text));

	return button;
}

kp::UIBase* kp::UIFactory::createUIElement(kp::UIType type, sf::RenderWindow& window, sf::Event& event)
{
	switch (type)
	{
	case kp::UIType::INPUT_FIELD:
		return createInputField(window, event);

	case kp::UIType::BUTTON:
		return createButton(window, event);

	default:
		return nullptr;
	}
}