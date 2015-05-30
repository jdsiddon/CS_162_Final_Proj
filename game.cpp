#include <iostream>
#include <string>

#include "Item.hpp"
#include "Player.hpp"

int main() {
  std::string tempName;

  std::cout << "Name of Player: ";  /* Get name for player. */
  getline(std::cin, tempName);

  Player *player1 = new Player(tempName); /* Create player. */
  std::cout << player1->getName() << std::endl;



  /* Free memory */
  delete player1;
  player1 = 0;

  return 0;
}
