#ifndef INPUT_FIELD_HPP
#define INPUT_FIELD_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class InputField
		: public kp::ObjectBase,
			public kp::IWindow,
			public kp::IEvent
	{
	private:
		void memoryAllocation();
		void initOfBaseTypes();
		void initRect();
		void initFont();
	protected:
		sf::RectangleShape* m_inputRect;
		unsigned int m_size;
		sf::Font* m_font;
		sf::String* m_text;

		void checkInput();
	public:
		InputField();
		InputField(const kp::InputField& copy);

		virtual void setWindow(sf::RenderWindow* window) override;
		virtual const sf::RenderWindow* getWindow() const  override;

		virtual void setEvent(sf::Event* event) override;
		virtual const sf::Event* getEvent() const override;

		void setPosition(sf::Vector2f position);
		const sf::Vector2f getPosition() const;

		void setText(sf::String& text);
		const sf::String* getText() const;

		bool contains(sf::Vector2f point) const;

		virtual void render() override;
		virtual void update(float dT) override;

		~InputField();
	};
}

#endif // !INPUT_FIELD_HPP