#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "player.h"
#include "block.h"

using namespace std;

 int main()
 {
    // Create the main window
    sf::RenderWindow App(sf::VideoMode(640, 480), "Clever Game Name");

    //starting the clock for smooth movement
    sf::Clock time_pass;

    //player class
    Player player_1 = Player(100.00, 0.00);

    //Vector of blocks
    vector<Block> total;
    //Another block
    Block wall = Block(50.00, 400.00, 550.00, 32.00);
    Block wall2 = Block(100.00, 264.00, 300.00, 32.00);
    Block wall3 = Block(432.00, 32.00, 32.00, 128.00);
    total.push_back(wall);
    total.push_back(wall2);
    total.push_back(wall3);

    // Start the game loop
    while (App.isOpen())
    {
        //if it's falling, gravity takes action
        player_1.set_jump(total);

        //Movement of the block
        player_1.move_left(total);
        player_1.move_right(total);

        // Process events
        sf::Event Event;
        while (App.pollEvent(Event))
        {
            // Close window : exit
            if (Event.type == sf::Event::Closed)
                App.close();

            //pressing escape
            if ((Event.type == sf::Event::KeyPressed) && (Event.key.code == sf::Keyboard::Escape))
                App.close();

        }

        // Clear screen
        App.clear();

        // Draw the sprite
        App.draw(player_1.get_shape());

        //draw the obstacle
        for(int i=0; i<total.size(); i++)
        {
            App.draw(total[i].get_shape());
        }

        // Update the window
        App.display();
    }

    return EXIT_SUCCESS;
 }

