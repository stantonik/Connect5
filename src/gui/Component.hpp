/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Component
 * @created     : dimanche mai 19, 2024 20:25:15 CEST
 */

#ifndef COMPONENT_HPP
#define COMPONENT_HPP


namespace MLS
{
  namespace GUI
  {
    class Panel;

    class Component
    {
      public:
        int const &line;
        bool const &selectable;
        Panel *panel;

        Component();

        friend Panel;

      protected:
        bool mSelectable = false;

      private:
        int mLine = 0;
    };
  }
}

#endif 

