/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Board
 * @created     : dimanche mai 19, 2024 16:00:21 CEST
 */

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Humain.hpp"
#include "Bot.hpp"
#include "Tile.hpp"

#include <vector>


namespace MLS
{
  class Board
  {
    public:
      int const &width, &height;
      int selected_column = 0;
      Player *players[2];
      Player *actual_player;

      Board(int width, int height);
      Board(Board const &board);

      friend Player;

      void add_players(Player *, Player *);
      void make_move();
      bool is_valid_move(int) const;
      bool full() const;
      std::vector<int> get_valid_moves() const;
      std::vector<Tile> get_alignement(int x, int y, int dx, int dy) const;
      WINDOW *get_window() const;

    private:
      int mWidth, mHeight;
      std::vector<Tile> mTiles;
  };
}

#endif 

