#include "Palette.hpp"

const kp::StateColor* kp::Palette::m_active = new kp::StateColor
{
	sf::Color(170, 170, 170, 255),
	sf::Color(70, 70, 70, 255),
	sf::Color(90, 90, 90, 255),
	sf::Color(40, 40, 40, 255),
	sf::Color(50, 50, 50, 255)
};

const kp::StateColor* kp::Palette::m_inactive = new kp::StateColor
{
	sf::Color(140, 140, 140, 255),
	sf::Color(40, 40, 40, 255),
	sf::Color(60, 60, 60, 255),
	sf::Color(10, 10, 10, 255),
	sf::Color(20, 20, 20, 255)
};