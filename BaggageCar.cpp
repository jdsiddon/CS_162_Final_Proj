#include <iostream> // Debugging.

#include "Room.hpp"
#include "BaggageCar.hpp"

/*********************************************************************
 ** Function: BaggageCar
 ** Description: Default BaggageCar constructor. Calls Room class
 ** default constructor and makes it an 'outside' room.
 ** Parameters: int roomNumber, room number of the room.
 ** Pre-Conditions: No BaggageCar created.
 ** Post-Conditions: BaggageCar created.
 *********************************************************************/
BaggageCar::BaggageCar(Room *previousCar)
  : Room(previousCar) {
}

/*********************************************************************
 ** Function: BaggageCar
 ** Description: Secondary BaggageCar constructor. Used to create
 ** the left and right ouside portions of the car.
 ** Parameters: int roomNumber, room number of the room. std::string side,
 ** "left" or "right" side of the car.
 ** Pre-Conditions: No BaggageCar created.
 ** Post-Conditions: BaggageCar created.
 *********************************************************************/
BaggageCar::BaggageCar(std::string side, Room *previousCar)
  : Room(side, previousCar) {
}

/*********************************************************************
 ** Function: ~BaggageCar
 ** Description: Default BaggageCar destructor.
 ** Parameters: None.
 ** Pre-Conditions: BaggageCar.
 ** Post-Conditions: BaggageCar object destroyed.
 *********************************************************************/
BaggageCar::~BaggageCar() {
  std::cout << "Delete";
}

std::string BaggageCar::getCustomFunction() {
  return "Tip the bag boy";
}

/*********************************************************************
 ** Function: getItem
 ** Description: Takes an item from the passed vector. Used to
 ** take items from a players bag.
 ** Parameters: string name, name of item to take. vector bagOfItems, bag
 ** full of items to check if item exists.
 ** Pre-Conditions: No item removed.
 ** Post-Conditions: Item removed from bag.
 *********************************************************************/
void BaggageCar::customBehavior(std::vector<Item*> bagOfItems) {
  Item *item1;

  /* Check to see if 'coin' are in the players bag of items. */
  for(int i = 0; i < bagOfItems.size(); i++) {
    //std::cout << bagOfItems[i]->getName();

    if(bagOfItems[i]->getName() == "coin") {
      item1 = bagOfItems[i];
      bagOfItems.erase(bagOfItems.begin() + i); /* Remove item from the players bag. */

      break;  /* Only need a single coin. */
    }
  }

  if (item1) {    /* Found a coin so we can pay off the Bag Boy. */
    std::cout << "Bag Boy: Hey thanks for the tip! You might go see what the bar tender knows\n"
              << "Also I think I saw a glass in one of the passenger cars that he was looking for" << std::endl;

    /* Toggle coins visible */
    for(int i = 0; i < items.size(); i++) {
      if(items[i]->getName() == "glass") {
        items[i]->setVisible(true);
      }
    }

  } else {
    std::cout << "Bag Boy: Don't bother me!\n"
              << "Well unless you have some incentive!" << std::endl;
  }
}

/*********************************************************************
 ** Function: talk
 ** Description: Talks to people in Bagger Car.
 ** Parameters: None.
 ** Pre-Conditions: No talking.
 ** Post-Conditions: Talking action complete.
 *********************************************************************/
void BaggageCar::talk() {
  std::cout << "Oye! I am the bag man!\n"
            << "Unless you have something worth my while"
            << "I am going to get back to enjoying the last few minutes"
            <<  " while we are still alive." << std::endl;
}
