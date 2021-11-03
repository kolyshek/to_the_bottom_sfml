#ifndef I_WINDOW
#define I_WINDOW

#include "coreMinimal.hpp"

namespace kp
{
	class IWindow
	{
	protected:
		sf::RenderWindow* m_window;
	public:
		virtual void setWindow(sf::RenderWindow* window) = 0;
		virtual const sf::RenderWindow* getWindow() const = 0;
	};
}

#endif // !I_WINDOW