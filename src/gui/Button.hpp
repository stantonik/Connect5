/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Button
 * @created     : dimanche mai 19, 2024 21:03:02 CEST
 */

#ifndef BUTTON_HPP
#define BUTTON_HPP

#include "ActionListener.hpp"
#include "Label.hpp"


namespace MLS
{
  namespace GUI
  {
    class Button : public Label, public IActionListener
    {
      public:
        IActionListener *action_listener;

        Button(std::string, IActionListener *, std::string = "");

        void action_performed(Button *) override;
    };
  }
}

#endif 

