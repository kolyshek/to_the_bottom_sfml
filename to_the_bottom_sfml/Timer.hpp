#ifndef TIMER_HPP
#define TIMER_HPP

#include "coreMinimal.hpp"

namespace kp
{
	enum class Limitation
	{
		Unknown = -1,
		Limited = 0,
		Unlimited = 1
	};

	class Timer
		: public kp::IBase,
			public kp::IActive
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
		virtual bool isActive() const override;

		void setLimitation(const kp::Limitation limitation);
		kp::Limitation getLimitation() const;

		void setLimit(float seconds);
		float getLimit() const;

		float getCurrentTime() const;

		bool isOver();
		void reset();

		virtual void render() override;
		virtual void update(float dT) override;
	};
}

#endif // !TIMER_HPP