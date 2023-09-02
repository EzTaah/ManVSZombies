#include "Game.hpp"
#include "SFML/Graphics.hpp"


int main()
{
    // === Create the window
    sf::RenderWindow window = sf::RenderWindow(sf::VideoMode(1366, 764), "2D-zombie-shooter");
    window.setFramerateLimit(144);

    // === Create the game ===
    Game game = Game(window);

    while(window.isOpen())
    {
        // === Update ===
        game.Update();

        // === Render ===
        game.Render();

        // === Process events ===
        sf::Event event;
        while(window.pollEvent(event))
        {
            switch(event.type)
            {
                // If the window is closed
                case sf::Event::Closed: 
                    window.close();
                    exit(EXIT_SUCCESS);

                default:
                    break;
            }
        }
    }
}