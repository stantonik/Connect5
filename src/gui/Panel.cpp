/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Panel
 * @created     : dimanche mai 19, 2024 20:20:59 CEST
 */

#include "Panel.hpp"


MLS::GUI::Panel *MLS::GUI::Panel::displayed = nullptr;

void MLS::GUI::Panel::display(Panel *panel)
{
  if (!panel) return;
  if (displayed) displayed->running = false;
  displayed = panel;
  panel->run();
}


MLS::GUI::Panel::Panel(WINDOW *window, std::string title) : window(window), title(title)
{
 
}

void MLS::GUI::Panel::add(MLS::GUI::Component *component)
{
  if (!component) return;
  component->mLine = components.size();
  component->panel = this;
  components.push_back(component);

  scroll_up();
  scroll_down();
}

void MLS::GUI::Panel::remove(int line)
{
  if (line < 0 || line > components.size() - 1) return;
  delete components[line];
  components.erase(components.begin() + line);

  scroll_up();
  scroll_down();
}

void MLS::GUI::Panel::clear()
{
  /* for (Component *component : components) delete component; */
  components.clear();
  selected_line = 0;
}

void MLS::GUI::Panel::run()
{
  running = true;

  display();
  while(running)
  {
    update();
    display();
  }
}

void MLS::GUI::Panel::display() const
{
  if (!window) return;

  int width, height;
  getmaxyx(window, height, width);

  ::wbkgd(window, COLOR_PAIR(1));
  ::wclear(window);

  ::wmove(window, 0, (width - title.size()) / 2);   
  ::wprintw(window, "%s", title.c_str());

  for (Component *component : components)
  {
    Label *label = static_cast<Label *>(component);

    if (label->line == selected_line) ::wattron(window, COLOR_PAIR(2));
    ::wmove(window, 2 + label->line, (width - label->label.size()) / 2);   
    ::wprintw(window, "%s", label->label.c_str());
    if (label->line == selected_line) ::wattroff(window, COLOR_PAIR(1));
  }

  ::wrefresh(window);
}

void MLS::GUI::Panel::update()
{
  int key = ::getch();

  if (key == KEY_UP)
  {
    scroll_up();
  }
  else if (key == KEY_DOWN)
  {
    scroll_down();
  }
  else if (key == '\n')
  {
    Component *component = components[selected_line];
    if (!component) return;
    if (component->selectable)
    {
      Button *button = static_cast<Button *>(component);
      button->action_performed(button);
    }
  }
}

void MLS::GUI::Panel::scroll_up()
{
  if (std::count_if(components.begin(), components.end(), [=](Component const *c) { return c->selectable == true; }) == 0) return;

  selected_line = (selected_line + components.size() - 1) % components.size();
  if (components[selected_line]->selectable == false) scroll_up();
}

void MLS::GUI::Panel::scroll_down()
{
  if (std::count_if(components.begin(), components.end(), [=](Component const *c) { return c->selectable == true; }) == 0) return;

  selected_line = (selected_line + 1) % components.size();
  if (components[selected_line]->selectable == false) scroll_down();
}
