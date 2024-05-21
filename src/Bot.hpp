/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Bot
 * @created     : dimanche mai 19, 2024 16:54:42 CEST
 */

#ifndef BOT_HPP
#define BOT_HPP

#include "Player.hpp"

#include <climits>


namespace MLS
{
  class Bot : public Player 
  {
    public:
      Bot();
      Bot(Board *);

    private:
      int get_column() const override;
      std::pair<int, int> min_max(Board board, int depth, bool maximizing_player, int alpha, int beta) const;

  };
}

#endif 

