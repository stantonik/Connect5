/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Tile
 * @created     : dimanche mai 19, 2024 15:50:44 CEST
 */

#ifndef TILE_HPP
#define TILE_HPP

#include <string>


namespace MLS
{
  enum class Color
  {
    WHITE = 1,
    BLACK,
    RED,
    YELLOW,
    BLUE
  };

  class Tile
  {
    public:
      int x = 0, y = 0;
      std::string token = " ";
      Color color = Color::WHITE;

      Tile();
      Tile(int x, int y, std::string token, Color = Color::WHITE);

      bool empty() const;

    private:

  };
}

#endif 

