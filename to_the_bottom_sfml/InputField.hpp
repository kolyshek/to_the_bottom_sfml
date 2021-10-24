#ifndef INPUT_FIELD_HPP
#define INPUT_FIELD_HPP

#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27

#include "UIBase.hpp"

namespace kp
{
	struct StateColors
	{
		sf::Color selectedTrueInputArea;
		sf::Color selectedTrueOutline;
		sf::Color selectedTrueDefaultText;
		sf::Color selectedTruePlayerText;

		sf::Color selectedFalseInputArea;
		sf::Color selectedFalseOutline;
		sf::Color selectedFalseDefaultText;
		sf::Color selectedFalsePlayerText;
	};

	class InputField
		: public kp::UIBase
	{
	private:
		void changeTextPositionToInputArea();
		void changeUIStatus();
		void changeMarkerValue();
		void changeMarkerPosition();
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

		kp::StateColors* m_stateColors;

		sf::Vector2f* m_edgeIndent;

		std::size_t m_markerPosition;
		std::size_t m_markerPositionBuffer;
	public:
		InputField();
		InputField(const kp::InputField& copy);

		void setInputArea(sf::RectangleShape& inputArea);
		void setPlayerInput(sf::String& playerInput);
		void setFont(sf::Font& font);
		void setDefaultText(sf::Text& defaultText);
		void setPlayerText(sf::Text& playerText);
		void setMaxLength(sf::Uint16 maxLength);
		void setStateColors(kp::StateColors& stateColors);
		void setEdgeIndent(sf::Vector2f& edgeIndent);
		void setMarkerPosition(std::size_t markerPosition);

		sf::RectangleShape* getInputArea();
		sf::String* getPlayerInput();
		sf::Font* getFont();
		sf::Text* getDefaultText();
		sf::Text* getPlayerText();
		sf::Uint16 getMaxLength();
		kp::StateColors* getStateColors();
		sf::Vector2f* getEdgeIndent();
		std::size_t getMarkerPosition();

		virtual void render() override;
		virtual void update(float dT) override;

		~InputField();
	};
}

#endif // !INPUT_FIELD_HPP