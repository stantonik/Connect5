/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : ActionListener
 * @created     : dimanche mai 19, 2024 19:52:10 CEST
 */

#ifndef ACTIONLISTENER_HPP
#define ACTIONLISTENER_HPP


namespace MLS
{
  namespace GUI
  {
    class Button;

    class IActionListener
    {
      public:
        virtual void action_performed(Button *) = 0;
    };

    class ActionListener : public IActionListener
    {
      public:
        void (*action)(Button *button);

        ActionListener(void (*action)(Button *));

        void action_performed(Button *) override;
    };
  }
}

#endif 

