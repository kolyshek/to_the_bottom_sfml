#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "UIBase.hpp"

namespace kp
{
	class Button
		: public kp::UIBase
	{
	private:
	protected:
		sf::RectangleShape* m_buttonArea;
		sf::Text* m_buttonText;
	public:
		Button();
		Button(kp::Button& copy);

		void setButtonArea(sf::RectangleShape& buttonArea);
		void setButtonText(sf::Text& buttonText);

		sf::RectangleShape* getButtonArea();
		sf::Text* getButtonText();

		virtual void render() override;
		virtual void update(float dT) override;

		~Button();
	};
}

#endif // !BUTTON_HPP