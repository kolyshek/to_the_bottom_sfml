#include <iostream>

#include "InputField.hpp"
#include "Button.hpp"

#include "Timer.hpp"

#include "UIFactory.hpp"

#include "SFML/Graphics.hpp"
#include "boost/multiprecision/cpp_int.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 500), "ToTheBottom", sf::Style::Titlebar | sf::Style::Close);
    sf::Event event;

    kp::InputField* inputField = dynamic_cast<kp::InputField*>(kp::UIFactory::createUIElement(kp::UIType::INPUT_FIELD,window, event));

    sf::Font font;
    if (font.loadFromFile("fonts/PixellettersFull.ttf"))
    {
        sf::Color fillColor(255, 255, 255, 255);
        unsigned int characterSize = 24;

        inputField->getInputArea()->setSize(sf::Vector2f(60.0f, 30.0f));
        inputField->getInputArea()->setOutlineThickness(2.0f);

        inputField->getPlayerText()->setFillColor(fillColor);
        inputField->getPlayerText()->setCharacterSize(characterSize);
        inputField->getPlayerText()->setFont(font);

        inputField->getDefaultText()->setFillColor(fillColor);
        inputField->getDefaultText()->setCharacterSize(characterSize);
        inputField->getDefaultText()->setFont(font);
        inputField->getDefaultText()->setString("Enter your text here");

        inputField->getTimer()->setTimeToStop(6.0f);

        inputField->getStateColors()->selectedTrueInputArea = sf::Color(200, 200, 200, 255);
        inputField->getStateColors()->selectedTrueOutline = sf::Color(120, 120, 120, 255);
        inputField->getStateColors()->selectedTrueDefaultText = sf::Color(90, 90, 90, 255);
        inputField->getStateColors()->selectedTruePlayerText = sf::Color(90, 90, 90, 255);

        inputField->getStateColors()->selectedFalseInputArea = sf::Color(150, 150, 150, 200);
        inputField->getStateColors()->selectedFalseOutline = sf::Color(70, 70, 70, 200);
        inputField->getStateColors()->selectedFalseDefaultText = sf::Color(40, 40, 40, 200);
        inputField->getStateColors()->selectedFalsePlayerText = sf::Color(40, 40, 40, 200);
    }

    while (window.isOpen())
    {
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed
                || sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape))
                window.close();
        }

        window.clear();

        inputField->render();
        inputField->update(0.01f);

        window.display();
    }

    delete inputField;

	return EXIT_SUCCESS;
}