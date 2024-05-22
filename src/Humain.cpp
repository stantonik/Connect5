/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Humain
 * @created     : dimanche mai 19, 2024 16:43:13 CEST
 */

#include "Humain.hpp"

#include "Board.hpp"

MLS::Humain::Humain() : Player()
{
  mType = PlayerType::HUMAIN;
}

MLS::Humain::Humain(Board *board) : Player(board)
{
  mType = PlayerType::HUMAIN;
}

int MLS::Humain::get_column() const
{
  ::flushinp();

  while(1)
  {
    int key = ::getch();
    
    if (key == KEY_LEFT)
    {
      pBoard->selected_column = (pBoard->selected_column + pBoard->width - 1) % pBoard->width;
    }
    else if (key == KEY_RIGHT)
    {
      pBoard->selected_column = (pBoard->selected_column + 1) % pBoard->width;
    }
    else if (key == '\n')
    {
      if (pBoard->is_valid_move(pBoard->selected_column)) return pBoard->selected_column;
    }

    pBoard->display();
  }
}
