#include "player.h"

Player::Player(double xp, double yp)
{
  pos_x = xp;
  pos_y = yp;
  pos_xf = 32;
  pos_yf = 32;
  face = 0;
  gravity = .1f;
  grav_direction = 270;
  velocity = 0.00;
  jump = true;
  square = sf::Rect<float>(pos_x, pos_y, pos_xf, pos_yf);
  square_draw.setSize(sf::Vector2f(pos_xf, pos_yf));
  square_draw.setPosition(pos_x, pos_y);
  square_draw.setOutlineColor(sf::Color::White);
}

double Player:: get_gravity() const
{
  return gravity;
}
int Player:: get_face() const
{
  return face;
}
bool Player:: get_jump() const
{
  return jump;
}
double Player:: get_x() const
{
  return pos_x;
}
double Player:: get_y() const
{
  return pos_y;
}
sf::RectangleShape& Player:: get_shape()
{
  return square_draw;
}
sf::Rect<float>& Player:: get_rect()
{
  return square;
}

void Player:: set_gravity(double g)
{
  if (g < 0) {return;}
  gravity = g;
}
void Player:: set_face(int f)
{
  if (f<0 || f>1) {return;}
  face = f;
}

void Player:: set_x(double x)
{
  pos_x = x;
  pos_xf = 32.00;
  square = sf::Rect<float>(pos_x, pos_y, pos_xf, pos_yf);
  square_draw.setPosition(pos_x, pos_y);
}
void Player:: set_y(double y)
{
  pos_y = y;
  pos_yf = 32.00;
  square = sf::Rect<float>(pos_x, pos_y, pos_xf, pos_yf);
  square_draw.setPosition(pos_x, pos_y);
}

