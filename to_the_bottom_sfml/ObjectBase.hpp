#ifndef OBJECT_BASE_HPP
#define OBJECT_BASE_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class ObjectBase
		: public kp::IBase, public kp::IActive
	{
	private:
		void initOfBaseTypes();
	public:
		ObjectBase();

		virtual void setActive(bool active) override;
		virtual bool isActive() const override;

		virtual void render() override;
		virtual void update(float dT) override;

		~ObjectBase();
	};
}

#endif // !OBJECT_BASE_HPP