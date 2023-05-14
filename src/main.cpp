#include <SFML/Graphics.hpp>
#include "World.h"
#include <iostream>
#include <cmath>

int main()
{
    // Had some trouble figuring out how to properly display the pixels bigger at certain window sizes
    // Credit to leonrode for their solution because apparently I can't do basic math
    // Repository: https://github.com/leonrode/falling-sand

    
    auto window = sf::RenderWindow{ { 800u, 800u }, "Falling Sand", sf::Style::Titlebar | sf::Style::Close };
    window.setFramerateLimit(120);

    Particle::particleSize = 5;

    World world(161, 161);

    sf::Clock clock;
    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        float fps = 1.0f / elapsed.asSeconds();

        std::cout << std::to_string(fps) << "\r" << std::flush;


        window.clear();
        for (auto event = sf::Event{}; window.pollEvent(event);)
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }

            if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
            {
                sf::Vector2i localPos = sf::Mouse::getPosition(window);

                int x = floor(localPos.x / Particle::particleSize);
                int y = floor(localPos.y / Particle::particleSize);

                // Starting a click and draggin off screen registers invalid window coords
                // Just make sure mouse is being clicked in the window
                if (localPos.x >= 0 && localPos.x <= window.getSize().x && localPos.y >= 0 && localPos.y <= window.getSize().y)
                    world.AddParticle(x, y);


            }
        }

        world.Update();
        window.draw(world);
        window.display();
    }


    return 0;
}