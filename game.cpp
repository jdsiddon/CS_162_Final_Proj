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
  int primaryMenuOption = 0;

  Train *train1 = new Train();  /* Create train. */

  //train1->listCars();     /* List cars in train, for debugging. */

  Player *bill = new Player("Tim Douglas", train1);  /* Create player. */

  do {
    /* State where Player is. */
    std::cout << "\nCurrently" << (bill->getCurrentRoom()->getOutside() ? " outside " : " inside ")
              << bill->getCurrentRoom()->getRoomType() << std::endl;

    /* Get the first level of action the player would like to take. */
    primaryMenuOption = bill->getCurrentRoom()->getRoomOptions();

    if (primaryMenuOption == 1) {        /* Talk to people in room. */
      bill->getCurrentRoom()->talk();

    } else if (primaryMenuOption == 2) { /* Search room. */
      Item *newItem = bill->getCurrentRoom()->search();

      if (newItem) {
        bill->addToBag(newItem);
      }

    } else if (primaryMenuOption == 3) { /* Move rooms. */
      bill->setCurrentRoom(bill->getCurrentRoom()->moveMenu());

    } else if (primaryMenuOption == 4) { /* Custom room function. */
      bill->getCurrentRoom()->customBehavior(bill->getBagItems());

    }
  } while(primaryMenuOption != 0);


  /* Free memory */
  delete train1;
  train1 = 0;

  delete bill;
  bill = 0;

  return 0;
}
