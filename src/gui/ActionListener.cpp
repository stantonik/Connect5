/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : ActionListener
 * @created     : dimanche mai 19, 2024 19:57:03 CEST
 */

#include "ActionListener.hpp"


MLS::GUI::ActionListener::ActionListener(void (*action)(Button *)) : action(action)
{
    
}

MLS::GUI::ActionListener::ActionListener(MLS::GUI::ActionListener const &action_listener)
{
  action = action_listener.action;
}

void MLS::GUI::ActionListener::action_performed(MLS::GUI::Button *button)
{
  if (action) action(button);
}
