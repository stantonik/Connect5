/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : Label
 * @created     : dimanche mai 19, 2024 20:44:02 CEST
 */

#include "Label.hpp"

MLS::GUI::Label::Label(std::string label, std::string id) : Component(), label(label)
{
  this->id = id.empty() ? label : id;
}

