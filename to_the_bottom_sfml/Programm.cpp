#include "Programm.hpp"

void kp::Programm::initOfBaseTypes()
{
	m_dT = 0.0f;
}

void kp::Programm::initWindow()
{
	m_window = new sf::RenderWindow;
	m_window->create(sf::VideoMode(400, 500), "ToTheBottom", sf::Style::Close);
}

void kp::Programm::initEvent()
{
	m_event = new sf::Event;
}

void kp::Programm::initClock()
{
	m_clock = new sf::Clock;
}

void kp::Programm::initTimer()
{
	m_timer = kp::GeneralFactory::createTimer();

	m_timer->setLimit(0.0f);
	m_timer->setLimitation(kp::Limitation::Unlimited);
	m_timer->setActive(true);
}

void kp::Programm::updateDt()
{
	m_dT = m_clock->restart().asSeconds();
}

void kp::Programm::updateEvent()
{
	while (m_window->pollEvent(*m_event))
	{
		if (m_event->type == sf::Event::Closed)
		{
			m_window->close();
		}
	}
}

kp::Programm::Programm()
{
	initOfBaseTypes();
	initWindow();
	initEvent();
	initClock();
	initTimer();
}

void kp::Programm::render()
{
}

void kp::Programm::update(float dT)
{
	updateDt();
	updateEvent();

	m_timer->update(dT);
}

void kp::Programm::run()
{
	while (m_window->isOpen())
	{
		m_window->clear(sf::Color::Black);

		render();
		update(m_dT);

		m_window->display();
	}
}

kp::Programm::~Programm()
{
	delete m_window;
	delete m_event;
	delete m_clock;
	delete m_timer;
}