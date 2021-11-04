#ifndef PALETTE_HPP
#define PALETTE_HPP

#include "coreMinimal.hpp"

namespace kp
{
	struct StateColor
	{
		sf::Color fill;
		sf::Color outline;
		sf::Color superimposed;
		sf::Color text;
		sf::Color marker;
	};

	class Palette
	{
	public:
		static const kp::StateColor* m_active;
		static const kp::StateColor* m_inactive;
	};
}

#endif // !PALETTE_HPP