/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Connect5
 * @created     : dimanche mai 19, 2024 15:47:11 CEST
 */

#ifndef CONNECT5_HPP
#define CONNECT5_HPP

#include "Board.hpp"

#include "gui/ActionListener.hpp"
#include "gui/Panel.hpp"
#include "gui/TextInput.hpp"

#include <ncurses.h>
#include <cstdlib>


namespace MLS
{
  class Connect5
  {
    public:
      Connect5() = delete;

      static void init();
      static void run();

    private:
      static int width, height;
      static std::string gametype;
      static std::string who_start;

      static Board *board;
      static GUI::ActionListener action_listener;
      static GUI::Panel panel;
      static void play();

      static void action_performed(GUI::Button *);
  };
}

#endif

