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
  std::string playerStatus = " ";

  Train *train1 = new Train();  /* Create train. */

  //train1->listCars();     /* List cars in train, for debugging. */

  Player *bill = new Player("Tim Douglas", train1);  /* Create player. */

  do {
    /* State where Player is. */
    std::cout << "\nCurrently" << (bill->getCurrentRoom()->getOutside() ? " outside " : " inside ")
              << bill->getCurrentRoom()->getRoomType() << std::endl;

    /* Get the first level of action the player would like to take. */
    primaryMenuOption = bill->getCurrentRoom()->getRoomOptions();

    /* Based on user response. */
    if (primaryMenuOption == 1) {        /* Talk to people in room. */
      /* DEBUGGING CODE */
      // std::cout << bill->getSobriety() << std::endl;
      bill->getCurrentRoom()->talk(bill->getSobriety());

    } else if (primaryMenuOption == 2) { /* Search room. */
      Item *newItem = bill->getCurrentRoom()->search();

      if (newItem) {
        bill->addToBag(newItem);
      }

    } else if (primaryMenuOption == 3) { /* Move rooms. */
      bill->setCurrentRoom(bill->getCurrentRoom()->moveMenu());

    } else if (primaryMenuOption == 4) { /* Custom room function. */
      playerStatus = bill->getCurrentRoom()->customBehavior(bill->getBagItems());

      if (playerStatus == "drunk") { /* See what player status comes back from custom room behavior. */
        bill->setSobriety(false);

      } else if (playerStatus == "rested") {
        bill->setSobriety(true);

      }
    }

  } while(primaryMenuOption != 5);  /* Keep going until user elects to quit. */


  /* Free memory */
  delete train1;
  train1 = 0;

  delete bill;
  bill = 0;

  return 0;
}
