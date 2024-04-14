#include "menu.hpp"
#include <SFML/Window/Event.hpp>

//Constructor to load the font
Menu::Menu(float width, float height) : width(width), height(height), selection(0) 
{
    //Error statement when loading fonts
    if (!font.loadFromFile("fonts/Creepster-Regular.ttf")) 
    {
        std::cout << "No font selected" << std::endl;
        return;
    }

    //Initializes all menu items and displays them
    std::string menuItems[] = { "Play", "Rules", "Multiplayer", "Exit" };
    //Displays everything
    for (int i = 0; i < 4; ++i) 
    {
        mainMenu[i].setFont(font);
        //Font color is white initially, when selecting it will change it to be blue
        mainMenu[i].setFillColor(sf::Color::White);
        mainMenu[i].setString(menuItems[i]);
        mainMenu[i].setCharacterSize(70);
        mainMenu[i].setPosition(400, 200 + 100 * i);
    }
    mainMenu[selection].setFillColor(sf::Color::Blue); //Highlights first item
}

//Destructor
Menu::~Menu()
{
    ;
}

//Getters
int Menu::getSelection() const
{
    return this->selection;
}
//Setters
void Menu::setNewSelection(const int& newSelection)
{
    this->selection = newSelection;
}

//Draws main menu
void Menu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < 4; ++i)
    {
        window.draw(mainMenu[i]);
    }
}

//Functions to move up and downn with arrow keys
void Menu::moveUp() 
{
    //Deselects first
    mainMenu[selection].setFillColor(sf::Color::White);
    //Move up (THIS BOUNDS THE RANGE FROM 0-3 because there are 4 items, which is why we have mod 4
    /*got hover idea from this video: https://www.youtube.com/watch?v=bOG8667yePY&t=613s */
    selection = (selection - 1 + 4) % 4;
    //Highlight new item
    mainMenu[selection].setFillColor(sf::Color::Blue);
}
//Same idea as move up
void Menu::moveDown() 
{
    //Deselects first
    mainMenu[selection].setFillColor(sf::Color::White);
    //Move up
    selection = (selection + 1) % 4;
    //Highlight new item
    mainMenu[selection].setFillColor(sf::Color::Blue);
}

//Menu wrapper to conserve space for main.cpp
void Menu::menuWrapper()
{
    //Display mode of 960x720 window
    sf::RenderWindow window(sf::VideoMode(960, 720), "Main Menu", sf::Style::Default);
    //Menu variable initialized
    Menu mainMenu(window.getSize().x, window.getSize().y);

    //While the window is still open,
    while (window.isOpen())
    {
        //Create the event type to process polls 
        sf::Event event;
        //while we are processing all events
        while (window.pollEvent(event))
        {
            //Closes window if user hits x
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            //Processes the key that was hit
            if (event.type == sf::Event::KeyReleased)
            {
                //If it was up, move up
                if (event.key.code == sf::Keyboard::Up)
                {
                    mainMenu.moveUp();
                }
                //If it was down move down
                if (event.key.code == sf::Keyboard::Down)
                {
                    mainMenu.moveDown();
                }
                //If hit return, we process the statement
                if (event.key.code == sf::Keyboard::Return)
                {
                    //We ge the selection
                    int choice = mainMenu.getSelection();
                    if (choice == 0)
                    {  
                        //Implement play here
                    }
                    else if (choice == 1)
                    {
                        //Implement rules page here
                    }
                    else if (choice == 2)
                    {
                        //implement multiplayer here
                    }
                    else if (choice == 3)
                    {
                        //Closes application here by applying .close function
                        window.close();
                    }
                    //Reset the window view after returning from choice 0 or 1
                    window.setView(window.getDefaultView());
                }
            }
        }

        window.clear();
        mainMenu.draw(window);
        window.display();
    }
}