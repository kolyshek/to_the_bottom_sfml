#ifndef I_EVENT
#define I_EVENT

#include "coreMinimal.hpp"

namespace kp
{
	class IEvent
	{
	protected:
		sf::Event* m_event;
	public:
		virtual void setEvent(sf::Event* event) = 0;
		virtual const sf::Event* getEvent() const = 0;
	};
}

#endif // !I_EVENT