#include <iostream>
#include <string>
#include "Train.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "BarCar.hpp"
#include <list>


/* Prototypes */


int main() {
  std::string tempName;

  Train *train1 = new Train();  /* Create train. */

  //train1->listCars();     /* List cars in train, for debugging. */

  Player *bill = new Player("Tim Douglas", train1);  /* Create player. */

  bill->getCurrentRoom()->roomOptions();

  /* Move rooms. */
  while (1 == 1) {
    std::cout << "Currently" << (bill->getCurrentRoom()->getOutside() ? " outside " : " inside ")
              << bill->getCurrentRoom()->getRoomType() << std::endl;
    bill->setCurrentRoom(bill->getCurrentRoom()->moveMenu());
  }


  // Open door.
  //bill->openDoor("east");

  delete train1;
  train1 = 0;



  // /* Free memory */
  // delete player1;
  // player1 = 0;

  return 0;
}
