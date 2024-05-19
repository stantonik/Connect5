/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Board
 * @created     : dimanche mai 19, 2024 16:06:19 CEST
 */

#include "Board.hpp"


MLS::Board::Board(int width, int height) : mWidth(width), mHeight(height), width(mWidth), height(mHeight)
{
  // Tiles init
  mTiles = std::vector<Tile>(width * height, Tile());

  for (int x = 0; x < width; ++x)
  {
    for (int y = 0; y < height; ++y)
    {
      mTiles[x + y * width] = Tile(x, y, " "); 
    }
  }
}

MLS::Board::Board(Board const &board) : width(mWidth), height(mHeight)
{
  mWidth = board.mWidth;
  mHeight = board.mHeight;
  actual_player = board.actual_player;
  mTiles = board.mTiles;
  players[0] = board.players[0];
  players[1] = board.players[1];
}

void MLS::Board::add_players(Player *p1, Player *p2)
{
  players[0] = p1;
  players[1] = p2;
  p1->opponent = p2;
  p2->opponent = p1;
  p1->pBoard = this;
  p2->pBoard = this;
  p1->tile = Player::PLAYER1_TILE;
  p2->tile = Player::PLAYER2_TILE;
}

bool MLS::Board::is_valid_move(int column) const
{
  if (column < 0 or column > width - 1) return false;
  return mTiles[column + 0 * width].empty();
}

std::vector<MLS::Tile> MLS::Board::get_alignement(int x, int y, int dx, int dy) const
{
  std::vector<Tile> alignement = { };

  for (int i = 0; i < 5; ++i)
  {
    int nx = x + i * dx;
    int ny = y + i * dy;
    if (nx >= 0 && nx < width && ny >= 0 && ny < height)
    {
      alignement.push_back(mTiles[nx + ny * width]);
    }
  }

  return alignement;
}

std::vector<int> MLS::Board::get_valid_moves() const
{
  std::vector<int> valid_moves = { };
  for (int x = 0; x < width; ++x)
  {
    if (is_valid_move(x))
    {
      valid_moves.push_back(x);
    }
  }

  return valid_moves;
}

bool MLS::Board::full() const
{
  return std::count_if(mTiles.begin(), mTiles.end(), [=](Tile const &t) { return t.token == " "; }) == 0;
}

::WINDOW *MLS::Board::get_window() const
{
  int w_height = 2 * height + 1;
  int w_width = 5 * width + 1;
  int console_width, console_height;
  getmaxyx(stdscr, console_height, console_width);

  ::WINDOW *win = ::subwin(stdscr, w_height + 3, w_width, (console_height - w_height) / 2, (console_width - w_width) / 2);

  ::wbkgd(win, COLOR_PAIR(1));

  for (int x = 0; x < width; ++x)
  {
    std::string xstr = std::to_string(x);
    std::string str;
    if (x == selected_column)
    {
      ::wattron(win, actual_player->tile.color);
      str = "  v  ";
    }
    else
    {
      str = "  " + xstr + std::string(2 - xstr.size() + 1, ' ');
    }
    ::wprintw(win, "%s", str.c_str());
    ::wattroff(win, actual_player->tile.color);
  }

  for (int y = 0; y < w_height; y++)
  {
    for (int x = 0; x < w_width; x++)
    {
      ::wmove(win, y + 2, x);
      if (y % 2 == 0)
      {
        if (x % 5 == 0)
        {
          if (x == 0 and y == 0) ::wprintw(win, "+"); 
          else if (x == 0 and y == w_height - 1) ::wprintw(win, "+"); 
          else if (x == w_width - 1 and y == 0) ::wprintw(win, "+"); 
          else if (x == w_width - 1 and y == w_height - 1) ::wprintw(win, "+"); 
          else if (x == 0) ::wprintw(win, "|"); 
          else if (x == w_width - 1) ::wprintw(win, "|"); 
          else if (y == 0) ::wprintw(win, "-"); 
          else if (y == w_height - 1)  ::wprintw(win, "-");  
          else ::wprintw(win, "+");
        }
        else ::wprintw(win, "-");
      }
      else
      {
        if (x % 5 == 0) ::wprintw(win, "|");
        else if (x % 5 == 2) 
        {
          int xx = (x - 1) / 5;
          int yy = (y - 1) / 2;
          Tile const &tile = mTiles[xx + yy * width];
          ::wattron(win, COLOR_PAIR(tile.color));
          ::wprintw(win, "%s", tile.token.c_str());
          ::wattroff(win, COLOR_PAIR(tile.color));
        }
      }
    }
  } 

  wrefresh(win);

  return win;
}

