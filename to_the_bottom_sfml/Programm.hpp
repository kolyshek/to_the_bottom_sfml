#ifndef PROGRAMM_H
#define PROGRAMM_H

#include "coreMinimal.hpp"

namespace kp
{
	class Programm
		: public kp::IBase
	{
	private:
		void memoryAllocation();
		void initOfBaseTypes();
		void initWindow();
		void initTimer();
	protected:
		sf::RenderWindow* m_window;
		sf::Event* m_event;
		sf::Clock* m_clock;

		kp::Timer* m_timer;

		float m_dT;

		void updateDt();
		void updateEvent();

		virtual void render() override;
		virtual void update(float dT) override;
	public:
		Programm();

		void run();
		
		~Programm();
	};
}

#endif // !PROGRAMM_H