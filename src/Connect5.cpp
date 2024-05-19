/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Connect5
 * @created     : dimanche mai 19, 2024 19:44:04 CEST
 */

#include "Connect5.hpp"


MLS::Board *MLS::Connect5::board = nullptr;
MLS::GUI::Panel MLS::Connect5::panel = MLS::GUI::Panel(stdscr, ""); 
int MLS::Connect5::width = 0, MLS::Connect5::height = 0;
std::string MLS::Connect5::gametype = "";
std::string MLS::Connect5::who_start = "";


void MLS::Connect5::init()
{
  // Init ncurses

  initscr();
  cbreak();
  noecho();
  curs_set(false);
  keypad(stdscr, true);

  start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLACK, COLOR_WHITE);
}

void MLS::Connect5::run()
{
  WINDOW *window = ::subwin(::stdscr, 20, 60, 0, 0);

  panel.window = window;
  panel.title = "Board setting";

  panel.add(new GUI::TextInput("Width : ", "", &action_listener, "width"));
  panel.add(new GUI::TextInput("Height: ", "", &action_listener, "height"));
  panel.add(new GUI::Label(""));
  panel.add(new GUI::Button("OK", &action_listener));
  panel.add(new GUI::Button("Quit", &action_listener));

  GUI::Panel::display(&panel);

  ::endwin();
}

void MLS::Connect5::action_performed(MLS::GUI::Button *button)
{
  if (button->id == "Quit")
  {
    GUI::Panel::displayed->running = false;
  }
  else if (button->id == "OK")
  {
    panel.clear();
    panel.title = "Game type";
    panel.add(new GUI::Button("Player vs Player", &action_listener, "pvp"));
    panel.add(new GUI::Button("Player vs Bot", &action_listener, "pvb"));
    panel.add(new GUI::Label(""));
    panel.add(new GUI::Button("Quit", &action_listener));
  }
  else if (button->id == "pvp" || button->id == "pvb")
  {
    gametype = button->id;
    panel.clear();
    panel.add(new GUI::Button((gametype == "pvp" ? "Player 1 starts" : "Player starts"), &action_listener, "p1"));
    panel.add(new GUI::Button((gametype == "pvp" ? "Player 2 starts" : "Bot starts"), &action_listener, "p2"));
    panel.add(new GUI::Button("Random start", &action_listener, "random"));
    panel.add(new GUI::Label(""));
    panel.add(new GUI::Button("Quit", &action_listener));
  }
  else if (button->id == "width")
  {
    GUI::TextInput *input = static_cast<GUI::TextInput *>(button);
    try
    {
      width = stoi(input->output);
      if (width < 5 || width > 20) throw -1;
    }
    catch(...)
    {
      input->label = input->name + "please enter a size between 5 and 20";
    }
  }
  else if (button->id == "height")
  {
    GUI::TextInput *input = static_cast<GUI::TextInput *>(button);
    try
    {
      height = stoi(input->output);
      if (height < 5 || height > 20) throw -1;
    }
    catch(...)
    {
      input->label = input->name + "please enter a size between 5 and 20";
    }
  }
  else if (button->id == "p1" || button->id == "p2" || button->id == "random")
  {
    who_start = button->id; 
    play();
  }
}

void MLS::Connect5::play()
{
  board = new Board(width, height);
  if (gametype == "pvp") board->add_players(new Humain(), new Humain());
  else if (gametype == "pvb") board->add_players(new Humain(), new Bot());

  if (who_start == "random") who_start = std::rand() % 2 == 0 ? "p1" : "p2";
  if (who_start == "p1") board->actual_player = board->players[0];
  else if (who_start == "p2") board->actual_player = board->players[1];

  bool gameover = false;
  ::wclear(GUI::Panel::displayed->window);

  while (!gameover)
  {
    ::WINDOW *board_win = board->get_window();

    board->actual_player->move();

    /* free(board_win); */
  }

  ::getch();
}

MLS::GUI::ActionListener MLS::Connect5::action_listener = GUI::ActionListener(action_performed);
