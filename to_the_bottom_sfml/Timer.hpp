#ifndef TIMER_HPP
#define TIMER_HPP

#include "coreMinimal.hpp"

namespace kp
{
	enum class Limitation
	{
		Unknown,
		Limited,
		Unlimited
	};

	class Timer
		: public kp::IBase, public kp::IActive
	{
	private:
		void initOfBaseTypes();
	protected:
		float m_begin;
		float m_end;

		kp::Limitation m_limitation;
	public:
		Timer();
		Timer(const kp::Timer& copy);

		virtual void setActive(bool active) override;
		virtual bool isActive() override;

		void setLimitation(const kp::Limitation limitation);
		const kp::Limitation getLimitation() const;

		void setLimit(float seconds);
		const float getLimit() const;

		const bool isOver() const;
		void reset();

		virtual void render() override;
		virtual void update(float dT) override;
	};
}

#endif // !TIMER_HPP