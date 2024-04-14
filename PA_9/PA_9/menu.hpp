#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
//Include the game stuff here,

#include <iostream>

//Class menu
class Menu
{
public:
	//Initialize constructor with the width and height at 0
	Menu(float width = 0.0, float height = 0.0);
	//Destructor
	~Menu();
	//Draws the menu through sfml render window
	void draw(sf::RenderWindow& window);
	//Functions to move up and downn with arrow keys
	void moveUp();
	void moveDown();
	//Getters
	int getSelection() const;
	//Setters
	void setNewSelection(const int& newSelection);
	//Wrapper
	void menuWrapper();
private:
	//Private members
	float width;
	float height;
	//Selection
	int selection;
	//Font we will be using
	sf::Font font;
	//Main menu selection, has 4 options
	sf::Text mainMenu[4];
};
