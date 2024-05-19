/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : TextInput
 * @created     : dimanche mai 19, 2024 23:32:13 CEST
 */

#ifndef TEXTINPUT_HPP
#define TEXTINPUT_HPP

#include "Button.hpp"

#include <ncurses.h>


namespace MLS
{
  namespace GUI
  {
    class TextInput : public Button
    {
      public:
        std::string name;
        std::string default_value;
        std::string const &output;

        TextInput(std::string, std::string, ActionListener *, std::string = "");

        void action_performed(Button *) override;

      private:
        std::string mOutput;
    };
  }
}

#endif 

