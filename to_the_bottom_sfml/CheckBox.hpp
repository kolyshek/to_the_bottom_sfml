#ifndef CHECK_BOX_HPP
#define CHECK_BOX_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class CheckBox
		: public kp::ObjectBase,
			public kp::IBase,
			public kp::IActive
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

		virtual void setActive(bool active) override;
		virtual bool isActive() override;

		virtual void render() override;
		virtual void update(float dT) override;

		~CheckBox();
	};
}

#endif // !CHECK_BOX_HPP