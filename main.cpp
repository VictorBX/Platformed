#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <ctime>
#include "player.h"
#include "block.h"

using namespace std;

bool coll_top (sf::Rect<float> &a, vector<Block> b);
bool coll_bottom (sf::Rect<float> &a, vector<Block> b);
bool coll_left (sf::Rect<float> &a, vector<Block> b);
bool coll_right (sf::Rect<float> &a, vector<Block> b);

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

     //velocity
     float vel = 0.00;
     float acc = 0.00;
     bool falling = true;

     //player stats
     cout << "Face: " << player_1.get_face() << endl;
     cout << "X: " << player_1.get_x() << endl;
     cout << "Y: " << player_1.get_y() << endl;
     cout << "Gravity: " << player_1.get_gravity() << endl;
     cout << total[0].get_x() << endl;
     cout << "Block vector: " << total.size() << endl;


     // Start the game loop
     while (App.isOpen())
     {
          //if it's falling, gravity takes action
          if(!coll_bottom(player_1.get_rect(), total))
          {
            if (falling)
            {
              acc =.003;
              vel += acc;
              if (vel>=1) {vel = 1;}
              player_1.set_y(player_1.get_y() + vel);
            }
            else
            {
              acc =.003;
              vel -= acc;
              if (vel<=0 || coll_top(player_1.get_rect(), total)) {vel = 0; falling  = true;}
              player_1.set_y(player_1.get_y() - vel);
            }
          }
          else
          {
            vel = 0.00;
            acc = 0.00;
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
            {
              falling = false;
              vel = 1;
              player_1.set_y(player_1.get_y() - .1f);
            }
          }

          //Movement of the block
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !coll_left(player_1.get_rect(), total))
          {
            player_1.set_x(player_1.get_x() - .25f);
          }
          if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !coll_right(player_1.get_rect(), total))
          {
            player_1.set_x(player_1.get_x() + .25f);
          }

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

bool coll_top (sf::Rect<float> &a, vector<Block> b)
{
  sf::Rect<float> c = sf::Rect<float>(a.left, a.top-1, a.width, a.height);
  for(int i=0; i<b.size(); i++)
  {
      if (c.intersects(b[i].get_rect()))
    {
      return true;
    }
  }
  return false;
}
bool coll_bottom (sf::Rect<float> &a, vector<Block> b)
{
  sf::Rect<float> c = sf::Rect<float>(a.left, a.top, a.width, a.height+1);
  for(int i=0; i<b.size(); i++)
  {
      if (c.intersects(b[i].get_rect()))
    {
      return true;
    }
  }
  return false;
}
bool coll_left (sf::Rect<float> &a, vector<Block> b)
{
  sf::Rect<float> c = sf::Rect<float>(a.left-0.1f, a.top, a.width, a.height);
  for(int i=0; i<b.size(); i++)
  {
      if (c.intersects(b[i].get_rect()))
    {
      return true;
    }
  }
  return false;
}
bool coll_right (sf::Rect<float> &a, vector<Block> b)
{
  sf::Rect<float> c = sf::Rect<float>(a.left, a.top, a.width+0.1f, a.height);
  for(int i=0; i<b.size(); i++)
  {
      if (c.intersects(b[i].get_rect()))
    {
      return true;
    }
  }
  return false;
}
