#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class Button
		: public kp::ObjectBase
	{
	private:
		void memoryAllocation();
		void initRect();
	protected:
		sf::RectangleShape* m_btnRect;
	public:
		Button();
		Button(kp::Button& copy);

		virtual void render() override;
		virtual void update(float dT) override;

		~Button();
	};
}

#endif // !BUTTON_HPP