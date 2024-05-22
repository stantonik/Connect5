/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : TextInput
 * @created     : dimanche mai 19, 2024 23:32:03 CEST
 */

#include "TextInput.hpp"
#include "Panel.hpp"


MLS::GUI::TextInput::TextInput(std::string name, std::string default_value, ActionListener *action_listener, std::string id) : Button(name + default_value, action_listener, id), name(name), default_value(default_value), output(mOutput)
{
  mOutput = default_value; 
}

void MLS::GUI::TextInput::action_performed(MLS::GUI::Button *button)
{
  if (!panel) return;

  ::echo();
  ::curs_set(true);

  label = name;
  panel->display();

  int width = getmaxx(panel->window);
  ::wmove(panel->window, line + 2, (width + label.size()) / 2);

  char input[32];
  ::wgetstr(panel->window, input);
  mOutput = std::string(input);
  label = name + output;

  ::noecho();
  ::curs_set(false);

  Button::action_performed(button);
}
