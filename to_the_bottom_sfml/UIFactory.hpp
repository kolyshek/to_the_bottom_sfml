#ifndef UI_FACTORY_HPP
#define UI_FACTORY_HPP

#include "SFML/Graphics.hpp"

namespace kp
{
	class UIBase;
	class InputField;
	class Button;

	enum class UIType
	{
		UNKNOWN = -1,
		INPUT_FIELD,
		BUTTON,
		MAX_TYPE
	};

	class UIFactory
	{
	private:
		static kp::InputField* createInputField(sf::RenderWindow& window, sf::Event& event);
		static kp::Button* createButton(sf::RenderWindow& window, sf::Event& event);
	public:
		static kp::UIBase* createUIElement(kp::UIType type, sf::RenderWindow& window, sf::Event& event);
	};
}

#endif // !UI_FACTORY_HPP