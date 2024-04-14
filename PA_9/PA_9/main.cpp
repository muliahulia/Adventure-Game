#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Graphics/RenderWindow.hpp>

#include "menu.hpp"

int main()
{
    /*
      sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
      sf::CircleShape shape(100.f);
      shape.setFillColor(sf::Color::Green);

      while (window.isOpen())
      {
          sf::Event event;
          while (window.pollEvent(event))
          {
              if (event.type == sf::Event::Closed)
                  window.close();
          }

          window.clear();
          window.draw(shape);
          window.display();
      }
    */
    //Main menu test
    Menu mainMenu;
    mainMenu.menuWrapper();
    return 0;
}
