#ifndef TIMER_HPP
#define TIMER_HPP

namespace kp
{
	enum class TimeDirection
	{
		UNKNOWN = -1,
		INCREASE,
		DECREASE,
		MAX_DIRECTION
	};

	class Timer
	{
	protected:
		float m_begin;
		float m_end;
		float m_beginBuffer;
		float m_endBuffer;

		bool m_run;

		TimeDirection m_direction;
	public:
		Timer();

		void setBegin(float begin);
		void setEnd(float end);
		void setTimerRun(bool timerRun);
		void setDirection(kp::TimeDirection direction);

		float getBegin();
		float getEnd();
		bool getTimerRun();
		kp::TimeDirection getDirection();

		bool isOver();

		void update(float dT);

		~Timer();
	};
}

#endif // !TIMER_HPP