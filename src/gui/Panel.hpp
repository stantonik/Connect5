/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Panel
 * @created     : dimanche mai 19, 2024 20:08:08 CEST
 */

#ifndef PANEL_HPP
#define PANEL_HPP

#include "Component.hpp"
#include "Label.hpp"
#include "Button.hpp"

#include <algorithm>
#include <string>
#include <vector>
#include <ncurses.h>


namespace MLS
{
  namespace GUI
  {
    class Panel
    {
      public:
        static Panel *displayed;

        std::vector<Component*> components = { };
        std::string title;
        WINDOW *window;

        bool running = false;
          
        Panel(WINDOW *, std::string title = "");

        static void display(Panel *);
        
        void add(Component *);
        void remove(size_t);
        void clear();
        void run();
        void display() const;
        void update();

      private:
        int selected_line = 0;

        void scroll_up();
        void scroll_down();
    };
  }
}

#endif 

