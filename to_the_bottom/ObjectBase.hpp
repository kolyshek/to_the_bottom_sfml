#ifndef OBJECT_BASE_HPP
#define OBJECT_BASE_HPP

#include "SFML/Graphics.hpp"

namespace kp
{
	class ObjectBase
	{
	protected:
		sf::RenderWindow* m_window;
		sf::Event* m_event;

		float m_dT;
	public:
		ObjectBase();

		void setWindow(sf::RenderWindow& window);
		void setEvent(sf::Event& event);

		sf::RenderWindow* getWindow();
		sf::Event* getEvent();

		virtual void render() = 0;
		virtual void update(float dT) = 0;

		~ObjectBase();
	};
}

#endif // !OBJECT_BASE_HPP