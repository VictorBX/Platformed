#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
#include "block.h"
using namespace std;

class Player
{
  private:
    //variables
    double gravity;
    double grav_direction;
    double pos_x;
    double pos_y;
    double pos_xf;
    double pos_yf;
    int face; //facing right
    bool falling;
    float velocity;
    float acceleration;
    //actual player
    sf::Rect<float> square;
    sf::RectangleShape square_draw;

    //methods
  public:
    //Constructor
    Player(double xp, double yp);
    //Accessor
    double get_gravity() const;
    int get_face() const;
    bool get_falling() const;
    double get_x() const;
    double get_y() const;
    sf::RectangleShape& get_shape();
    sf::Rect<float>& get_rect();
    //Mutators
    void set_gravity(double g);
    void set_face(int f);
    void set_x(double x);
    void set_y(double y);
    void set_jump(vector<Block> blocks);
    void move_left(vector<Block> blocks);
    void move_right(vector<Block> blocks);

    //collisions
    bool coll_top (vector<Block> b);
    bool coll_bottom (vector<Block> b);
    bool coll_left (vector<Block> b);
    bool coll_right (vector<Block> b);

};

#endif // PLAYER_H_INCLUDED
