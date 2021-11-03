#ifndef WIDGET_FACTORY_HPP
#define WIDGET_FACTORY_HPP

#include "coreMinimal.hpp"

namespace kp
{
    class InputField;
    class Button;
    class CheckBox;

    class WidgetFactory
    {
    public:
        static kp::InputField* createInputField(sf::RenderWindow* window, sf::Event* event);
        static kp::Button* createButton(sf::RenderWindow* window, sf::Event* event);
        static kp::CheckBox* createCheckBox(sf::RenderWindow* window, sf::Event* event);
    };
}

#endif // !WIDGET_FACTORY_HPP