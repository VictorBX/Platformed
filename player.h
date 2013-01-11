#ifndef PLAYER_H_INCLUDED
#define PLAYER_H_INCLUDED

#include <SFML/Graphics.hpp>
#include <iostream>
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
    bool jump;
    double velocity;
    //actual player
    sf::Rect<float> square;
    sf::RectangleShape square_draw;

    //methods
  public:
    //COnstructor
    Player(double xp, double yp);
    //Accessor
    double get_gravity() const;
    int get_face() const;
    bool get_jump() const;
    double get_x() const;
    double get_y() const;
    sf::RectangleShape& get_shape();
    sf::Rect<float>& get_rect();
    //Mutators
    void set_gravity(double g);
    void set_face(int f);
    void set_x(double x);
    void set_y(double y);

};

#endif // PLAYER_H_INCLUDED
