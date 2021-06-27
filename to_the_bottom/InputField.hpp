#ifndef INPUT_FIELD_HPP
#define INPUT_FIELD_HPP

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

#include "UIBase.hpp"

namespace kp
{
	class InputField
		: public kp::UIBase
	{
	private:
		void changeFieldColors();

		void insertText();
		void eraseText();
		void changeText();
	protected:
		sf::RectangleShape* m_inputArea;

		sf::String* m_playerInput;

		sf::Font* m_font;
		sf::Text* m_defaultText;
		sf::Text* m_playerText;

		sf::Uint16 m_maxLength;
	public:
		InputField();
		InputField(const kp::InputField& copy);

		void setInputArea(sf::RectangleShape& inputArea);
		void setPlayerInput(sf::String& playerInput);
		void setFont(sf::Font& font);
		void setDefaultText(sf::Text& defaultText);
		void setPlayerText(sf::Text& playerText);
		void setMaxLength(sf::Uint16 maxLength);

		sf::RectangleShape* getInputArea();
		sf::String* getPlayerInput();
		sf::Font* getFont();
		sf::Text* getDefaultText();
		sf::Text* getPlayerText();
		sf::Uint16 getMaxLength();

		virtual void render() override;
		virtual void update() override;

		~InputField();
	};
}

#endif // !INPUT_FIELD_HPP