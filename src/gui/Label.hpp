/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Label
 * @created     : dimanche mai 19, 2024 20:39:52 CEST
 */

#ifndef LABEL_HPP
#define LABEL_HPP

#include "Component.hpp"

#include <string>


namespace MLS
{
  namespace GUI
  {
    class Label : public Component
    {
      public:
        std::string label;
        std::string id;

        Label(std::string label, std::string id = "");
    };
  }
}

#endif 

