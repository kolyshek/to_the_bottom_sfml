#ifndef TIMER_HPP
#define TIMER_HPP

namespace kp
{
	class Timer
	{
	protected:
		float m_timeToStop;
		float m_timeBuffer;

		bool m_run;
	public:
		Timer();

		void setTimeToStop(float timeToStop);
		void setTimerStatus(bool timerStatus);

		float getTimeToStop();
		bool getTimerStatus();

		bool timeIsOver();

		void update(float m_dT);

		~Timer();
	};
}

#endif // !TIMER_HPP