/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Player
 * @created     : dimanche mai 19, 2024 15:56:26 CEST
 */

#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <algorithm>
#include <string>
#include <vector>

#include "Tile.hpp"


namespace MLS
{
  class Board;

  enum class PlayerType
  {
    VOID,
    BOT,
    HUMAIN
  };

  class Player
  {
    public:
      static const Tile PLAYER1_TILE;
      static const Tile PLAYER2_TILE;

      PlayerType const &type;
      Tile tile;
      Player *opponent = nullptr;

      Player();
      Player(Board *);

      friend Board;

      void move(int) const;
      void move() const;
      int get_score() const;
      bool winner() const;

    protected:
      Board *pBoard = nullptr;
      PlayerType mType = PlayerType::VOID;

      virtual int get_column() const = 0;

    private:
      int evaluate(std::vector<Tile>) const;
  };
}

#endif 

