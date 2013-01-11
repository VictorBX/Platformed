#ifndef BLOCK_H_INCLUDED
#define BLOCK_H_INCLUDED

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace std;

class Block
{
  private:
    double pos_x;
    double pos_y;
    double pos_xf;
    double pos_yf;
    //actual block
    sf::Rect<float> block;
    sf::RectangleShape block_draw;

  public:
    Block(double xp, double yp, double xpf, double ypf);
    double get_x() const;
    double get_y() const;
    sf::RectangleShape& get_shape();
    sf::Rect<float>& get_rect();

};

#endif // BLOCK_H_INCLUDED
