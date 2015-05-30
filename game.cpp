#include <iostream>
#include <string>

#include "Item.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "BarCar.hpp"
#include "Queue.hpp"

/* Prototypes */
Queue* createTrain();


int main() {
  std::string tempName;

  std::cout << "Name of Player: ";  /* Get name for player. */
  getline(std::cin, tempName);

  Player *player1 = new Player(tempName); /* Create player. */
  std::cout << player1->getName() << std::endl;

  createTrain();  /* Create the train. */

  /* DEBUGGING CODE */
  // std::cout << barCar->getRoomType() << std::endl; /* Get room name */
  /* END DEBUGGING CODE */





  /* Free memory */
  delete player1;
  player1 = 0;

  return 0;
}

Queue* createTrain() {
  /* DEBUGGING CODE, create test room with outside spaces */
  int barCarNum = 1;
  int leftCarNum = 2;
  int rightCarNum = 3;

  Room *barCar = new BarCar(barCarNum);
  Room *leftCar = new BarCar(leftCarNum);
  Room *rightCar = new BarCar(rightCarNum);

  Queue *train = new Queue();

  for (int i = 0; i < 4; i++) {
    /* Add car to train */
    train->add(barCar, leftCar, rightCar);
    std::cout << std::endl;
  }
  /* END DEBUGGING CODE, create test room with outside spaces */
  return train;
}
