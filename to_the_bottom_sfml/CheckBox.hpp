#ifndef CHECK_BOX_HPP
#define CHECK_BOX_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class CheckBox
		: public kp::ObjectBase
	{
	private:
		void memoryAllocation();
		void initRect();
	protected:
		sf::RectangleShape* m_checkRect;
	public:
		CheckBox();
		CheckBox(const kp::CheckBox& copy);

		bool contains(sf::Vector2f point) const;

		virtual void render() override;
		virtual void update(float dT) override;

		~CheckBox();
	};
}

#endif // !CHECK_BOX_HPP