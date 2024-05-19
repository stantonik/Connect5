/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Humain
 * @created     : dimanche mai 19, 2024 16:42:31 CEST
 */

#ifndef HUMAIN_HPP
#define HUMAIN_HPP

#include "Player.hpp"

#include <ncurses.h>


namespace MLS
{
  class Humain : public MLS::Player
  {
    public:
      Humain();
      Humain(Board *);

    private:
      int get_column() const override;
  };
}

#endif 

