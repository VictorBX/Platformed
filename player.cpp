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
  acceleration = 0.00;
  falling = true;
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
bool Player:: get_falling() const
{
  return falling;
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

void Player:: set_jump(vector<Block> blocks)
{
    if(!coll_bottom(blocks))
    {
        if (falling)
        {
            acceleration =.003;
            velocity += acceleration;
            if (velocity>=1) {velocity = 1;}
            set_y(get_y() + velocity);
        }
        else
        {
            acceleration =.003;
            velocity -= acceleration;
            if (velocity<=0 || coll_top(blocks)) {velocity = 0; falling  = true;}
            set_y(get_y() - velocity);
        }
    }
    else
    {
        velocity = 0.00;
        acceleration = 0.00;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
        {
            falling = false;
            velocity = 1;
            set_y(get_y() - .1f);
        }
    }
}

void Player:: move_left(vector<Block> blocks)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && !coll_left(blocks))
    {
        set_x(get_x() - .25f);
    }
}
void Player:: move_right(vector<Block> blocks)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right) && !coll_right(blocks))
    {
        set_x(get_x() + .25f);
    }
}

bool Player:: coll_top (vector<Block> b)
{
    sf::Rect<float> c = sf::Rect<float>(square.left, square.top-1, square.width, square.height);
    for(int i=0; i<b.size(); i++)
    {
        if (c.intersects(b[i].get_rect()))
        {
            return true;
        }
    }
    return false;
}
bool Player:: coll_bottom (vector<Block> b)
{
    sf::Rect<float> c = sf::Rect<float>(square.left, square.top, square.width, square.height+1);
    for(int i=0; i<b.size(); i++)
    {
        if (c.intersects(b[i].get_rect()))
        {
            return true;
        }
    }
    return false;
}
bool Player:: coll_left (vector<Block> b)
{
    sf::Rect<float> c = sf::Rect<float>(square.left-0.1f, square.top, square.width, square.height);
    for(int i=0; i<b.size(); i++)
    {
        if (c.intersects(b[i].get_rect()))
        {
            return true;
        }
    }
    return false;
}
bool Player:: coll_right (vector<Block> b)
{
    sf::Rect<float> c = sf::Rect<float>(square.left, square.top, square.width+0.1f, square.height);
    for(int i=0; i<b.size(); i++)
    {
        if (c.intersects(b[i].get_rect()))
        {
            return true;
        }
    }
    return false;
}

