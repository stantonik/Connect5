/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Button
 * @created     : dimanche mai 19, 2024 21:07:55 CEST
 */

#include "Button.hpp"


MLS::GUI::Button::Button(std::string label, IActionListener *action_listener, std::string id) : Label(label, id), action_listener(action_listener)
{
  mSelectable = true; 
}

void MLS::GUI::Button::action_performed(MLS::GUI::Button *button)
{
  if (action_listener) action_listener->action_performed(button);
}

