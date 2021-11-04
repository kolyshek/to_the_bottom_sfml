#include "WidgetFactory.hpp"

#include "InputField.hpp"
#include "Button.hpp"
#include "CheckBox.hpp"

kp::InputField* kp::WidgetFactory::createInputField(sf::RenderWindow* window, sf::Event* event)
{
	kp::InputField* inputField = new kp::InputField;

	inputField->setWindow(window);
	inputField->setEvent(event);
	inputField->setPosition(sf::Vector2f(16.0f,
		static_cast<float>(window->getSize().y) / 2.0f));
	sf::String str("Enter here");
	inputField->setText(str);

	return inputField;
}

kp::Button* kp::WidgetFactory::createButton(sf::RenderWindow* window, sf::Event* event)
{
	kp::Button* button = new kp::Button;

	return button;
}

kp::CheckBox* kp::WidgetFactory::createCheckBox(sf::RenderWindow* window, sf::Event* event)
{
	kp::CheckBox* checkBox = new kp::CheckBox;

	return checkBox;
}