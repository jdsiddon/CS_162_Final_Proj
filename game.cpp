#include <iostream>
#include <string>
#include <list>
#include <ctime>
#include <cstdlib>

/* Custom Classes */
#include "Train.hpp"
#include "Item.hpp"
#include "Player.hpp"
#include "Room.hpp"
#include "BarCar.hpp"


int main() {
  std::string tempName;
  std::string playerStatus = " ";
  int primaryMenuOption = 0;

  Train *train1 = new Train();  /* Create train. */

  Player *bill = new Player("Tim Douglas", train1);  /* Create player. */

  clock_t startTime = clock();  /* Start timer */
  double secondsPassed = 0.0;
  double secondsUntilDisaster = 20.0;

  bool crashed = false;
  bool stopped = false;

  while(!crashed || stopped) {

    do {
      // /* Update the amount of time that the train has been moving. */
      // std::cout << "secondsUntilDisaster: " << secondsUntilDisaster << std::endl;
      // std::cout << "startTime: " << startTime << std::endl;
      // clock_t tempClock = clock();
      // std::cout << "clockTime: " << tempClock << std::endl;
      // std::cout << "clockTime - startTime: " << tempClock - startTime << std::endl;
      //
      // std::cout << "startTime: " << startTime << std::endl;
      // secondsUntilDisaster-=1;
      // std::cout << secondsPassed << " cps: " << CLOCKS_PER_SEC << std::endl;
      // secondsPassed = (clock() - startTime) / CLOCKS_PER_SEC;
      // std::cout << secondsPassed << " cps: " << CLOCKS_PER_SEC << std::endl;
      // secondsPassed-=1;
      //
      // if(secondsPassed >= secondsUntilDisaster) { /* Time limit has been reached! */
      //   crashed = true;
      //   continue;
      // }

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

        } else if (playerStatus == "fixed") { /* Brake lever was turned into to passengers! Train is fixed. */
          std::cout << "Train comes to a screeching hault!" << std::endl;
          stopped = true; /* Stop train. */
        }
      }

      /* Check time passed */

    } while(primaryMenuOption != 5);  /* Keep going until user elects to quit. */

  } /* End timer while loop. */

  if (crashed == true) {
    std::cout << "Train Crashed!!!! Everyone died :(" << std::endl;

  } else {
    std::cout << "You stopped the train!!!! Everyone is so happy :)" << std::endl;

  }

  /* Free memory */
  delete train1;
  train1 = 0;

  delete bill;
  bill = 0;

  return 0;
}
