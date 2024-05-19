/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Player
 * @created     : dimanche mai 19, 2024 15:59:07 CEST
 */

#include "Player.hpp"

#include "Board.hpp"


const MLS::Tile MLS::Player::PLAYER1_TILE = MLS::Tile(0, 0, "X", MLS::Color::RED);
const MLS::Tile MLS::Player::PLAYER2_TILE = MLS::Tile(0, 0, "O", MLS::Color::YELLOW);


MLS::Player::Player() : type(mType)
{

}

MLS::Player::Player(Board *board) : pBoard(board), type(mType)
{

}

void MLS::Player::move(int column) const
{
  for (int y = pBoard->height - 1; y >= 0; --y)
  {
    if (pBoard->mTiles[column + y * pBoard->width].empty())
    {
      pBoard->mTiles[column + y * pBoard->width] = tile;
      break;
    }
  }

  pBoard->actual_player = opponent;
}

void MLS::Player::move() const
{
  move(get_column());
}

int MLS::Player::get_score() const
{
  int score = 0;

  for (int y = 0; y < pBoard->height; ++y) 
  {
    for (int x = 0; x < pBoard->width; ++x) 
    {
      score += evaluate(pBoard->get_alignement(x, y, 1, 0));
      score += evaluate(pBoard->get_alignement(x, y, 0, 1));
      score += evaluate(pBoard->get_alignement(x, y, 1, 1));
      score += evaluate(pBoard->get_alignement(x, y, 1, -1));
    }
  }

  return score;
}

int MLS::Player::evaluate(std::vector<Tile> alignement) const
{
  int score = 0;

  int player_count = std::count_if(alignement.begin(), alignement.end(), [=](Tile const &t) { return t.token == tile.token; });
  int opponent_count = std::count_if(alignement.begin(), alignement.end(), [=](Tile const &t) { return t.token == opponent->tile.token; });
  int empty_count = std::count_if(alignement.begin(), alignement.end(), [=](Tile const &t) { return t.token == " "; });

  if (player_count == 4 and empty_count == 1) score += 50;
  else if (player_count == 3 and empty_count == 2) score += 10;
  else if (player_count == 2 and empty_count == 3) score += 5;

  if (opponent_count == 4 and empty_count == 1) score += -20;

  return score;
}

bool MLS::Player::winner() const
{
  for (int y = 0; y < pBoard->height; ++y) 
  {
    for (int x = 0; x < pBoard->width; ++x) 
    {
      std::vector<Tile> h_align = pBoard->get_alignement(x, y, 1, 0);
      std::vector<Tile> v_align = pBoard->get_alignement(x, y, 0, 1);
      std::vector<Tile> d1_align = pBoard->get_alignement(x, y, 1, 1);
      std::vector<Tile> d2_align = pBoard->get_alignement(x, y, 1, -1);

      int h_nb = std::count_if(h_align.begin(), h_align.end(), [=](Tile const &t) { return t.token == tile.token; });
      int v_nb = std::count_if(v_align.begin(), v_align.end(), [=](Tile const &t) { return t.token == tile.token; });
      int d1_nb = std::count_if(d1_align.begin(), d1_align.end(), [=](Tile const &t) { return t.token == tile.token; });
      int d2_nb = std::count_if(d2_align.begin(), d2_align.end(), [=](Tile const &t) { return t.token == tile.token; });

      if (h_nb == 5 || v_nb == 5 || d1_nb == 5 || d2_nb == 5) return true;
    }
  }

  return false;
}

