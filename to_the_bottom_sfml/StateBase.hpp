#ifndef STATE_BASE_HPP
#define STATE_BASE_HPP

#include "coreMinimal.hpp"

namespace kp
{
	class StateBase
		: public kp::IEvent
	{
	private:
	protected:
	public:
		StateBase();

		virtual void setEvent(sf::Event* event) override;
		virtual const sf::Event* getEvent() const override;

		~StateBase();
	};
}

#endif // !STATE_BASE_HPP