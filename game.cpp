#include <iostream>
#include <string>

#include "Item.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "BarCar.hpp"
#include "Queue.hpp"

int main() {
  std::string tempName;

  std::cout << "Name of Player: ";  /* Get name for player. */
  getline(std::cin, tempName);

  Player *player1 = new Player(tempName); /* Create player. */
  std::cout << player1->getName() << std::endl;

  /* Create test room */
  int barCarNum = 1;
  int leftCarNum = 2;
  int rightCarNum = 3;
  Room *barCar = new BarCar(barCarNum);
  Room *leftCar = new BarCar(leftCarNum);
  Room *rightCar = new BarCar(rightCarNum);

  /* DEBUGGING CODE */
  // std::cout << barCar->getRoomType() << std::endl; /* Get room name */
  /* END DEBUGGING CODE */


  Queue *train = new Queue();
  /* Add car to train */
  train->add(barCar, leftCar, rightCar);

  Room *currentCar = train->getCurrentNode();

  std::cout << currentCar->getRoomType();


  /* Free memory */
  delete player1;
  player1 = 0;

  return 0;
}
