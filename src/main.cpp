/**
 * @author      : stantenik (stantenik@stantenik-G1S)
 * @file        : main
 * @created     : dimanche mai 19, 2024 15:19:10 CEST
 */

#include "Connect5.hpp"

#ifndef DEBUG
int main()
{
  MLS::Connect5::init();
  MLS::Connect5::run();

  return 0;
}
#endif 