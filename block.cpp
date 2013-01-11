#include "block.h"

Block::Block(double xp, double yp, double xpf, double ypf)
{
  pos_x = xp;
  pos_y = yp;
  pos_xf = xpf;
  pos_yf = ypf;
  block = sf::Rect<float>(pos_x, pos_y, pos_xf, pos_yf);
  //block_draw. sf::Shape::Rectangle(pos_x, pos_y, pos_xf, pos_yf,sf::Color::Green, 0,sf::Color::Green);
  block_draw.setSize(sf::Vector2f(pos_xf, pos_yf));
  block_draw.setPosition(pos_x, pos_y);
  block_draw.setFillColor(sf::Color::Green);
}
double Block:: get_x() const
{
  return pos_x;
}
double Block:: get_y() const
{
  return pos_y;
}

sf::RectangleShape& Block:: get_shape()
{
  return block_draw;
}
sf::Rect<float>& Block:: get_rect()
{
  return block;
}
