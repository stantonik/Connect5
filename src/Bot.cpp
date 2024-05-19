/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Bot
 * @created     : dimanche mai 19, 2024 17:02:36 CEST
 */

#include "Bot.hpp"

#include "Board.hpp"


MLS::Bot::Bot() : Player()
{
  mType = PlayerType::BOT;
}

MLS::Bot::Bot(Board *board) : Player(board)
{
  mType = PlayerType::BOT;
}

std::pair<int, int> MLS::Bot::min_max(Board &board, int depth, bool maximizing_player, int alpha, int beta) const
{
  if (depth == 0)
  {
    return std::make_pair(-1, get_score() - opponent->get_score());
  }

  if (maximizing_player)
  {
    int max_eval = INT_MIN;
    int best_move = -1;
    for (int move : board.get_valid_moves())
    {
      Board temp_board = Board(*pBoard);
      this->move(move);
      int eval_score = min_max(temp_board, depth - 1, false, alpha, beta).second;
      if (eval_score > max_eval)
      {
        max_eval = eval_score;
        best_move = move;
      }
      alpha = std::max(alpha, eval_score);
      if (beta <= alpha) break;
    }
    return std::make_pair(best_move, max_eval);
  }
  else
  {
    int min_eval = INT_MAX;
    int best_move = -1;
    for (int move : pBoard->get_valid_moves())
    {
      Board temp_board = Board(*pBoard);
      opponent->move(move);
      int eval_score = min_max(temp_board, depth - 1, true, alpha, beta).second;
      if (eval_score < min_eval)
      {
        min_eval = eval_score;
        best_move = move;
      }
      beta = std::min(beta, eval_score);
      if (beta <= alpha) break;
    }
    return std::make_pair(best_move, min_eval);
  }
}

int MLS::Bot::get_column() const
{
  return min_max(*pBoard, 4, true, INT_MIN, INT_MAX).first;
}

