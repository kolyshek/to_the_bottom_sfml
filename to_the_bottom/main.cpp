#include <iostream>

#include "InputField.hpp"
#include "Button.hpp"

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

        inputField->getPlayerText()->setFillColor(fillColor);
        inputField->getPlayerText()->setCharacterSize(characterSize);
        inputField->getPlayerText()->setFont(font);

        inputField->getDefaultText()->setFillColor(fillColor);
        inputField->getDefaultText()->setCharacterSize(characterSize);
        inputField->getDefaultText()->setFont(font);
        inputField->getDefaultText()->setString("Enter your text here");
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
        inputField->update();

        window.display();
    }

    delete inputField;

	return EXIT_SUCCESS;
}