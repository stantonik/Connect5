/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Tile
 * @created     : dimanche mai 19, 2024 15:55:04 CEST
 */

#include "Tile.hpp"

MLS::Tile::Tile()
{
    
}

MLS::Tile::Tile(int x, int y, std::string token, Color color) : x(x), y(y), token(token), color(color)
{

}

bool MLS::Tile::empty() const
{
  return token == " ";
}
