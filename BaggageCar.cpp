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

/*********************************************************************
 ** Function: getCustomFunction
 ** Description: Returns a breif string describing the custom function
 ** available in the room type.
 ** Parameters: None.
 ** Pre-Conditions: Special function unknown.
 ** Post-Conditions: Special function known.
 *********************************************************************/
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
std::string BaggageCar::customBehavior(std::vector<Item*> bagOfItems) {
  Item *item1 = NULL;

  /* Check to see if 'coin' are in the players bag of items. */
  for(int i = 0; i < bagOfItems.size(); i++) {
    //std::cout << bagOfItems[i]->getName();

    if(bagOfItems[i]->getName() == "coin") {
      item1 = bagOfItems[i];
      bagOfItems.erase(bagOfItems.begin() + i); /* Remove item from the players bag. */

      break;  /* Only need a single coin. */
    }
  }

  std::cout << "\n";
  if (item1) {    /* Found a coin so we can pay off the Bag Boy. */
    std::cout << "Bag Boy: \"Hey thanks for the tip! You might go see what the bar tender knows\n"
              << "Also I think I saw a glass in one of the passenger cars that he was looking for\"" << std::endl;

    /* Toggle coins visible */
    //train1->toggleItemVisibility("glass");
    // for(int i = 0; i < items.size(); i++) {
    //   std::cout << items[i]->getName() << std::endl;
    //   if(strcmp(items[i]->getName().c_str(), "glass") == 0) {
    //     std::cout << "Glass Found!" << std::endl;
    //     items[i]->setVisible(true);
    //   }
    // }

  } else {
    std::cout << "Bag Boy: \"Come back when you have some money. I don't work for free!\"" << std::endl;
  }
}

/*********************************************************************
 ** Function: talk
 ** Description: Talks to people in Bagger Car.
 ** Parameters: None.
 ** Pre-Conditions: No talking.
 ** Post-Conditions: Talking action complete.
 *********************************************************************/
void BaggageCar::talk(bool drunk) {
  if(getOutside()) {
    std::cout << "\n'No one in their right mind is on the outside of a train to talk!'\n";

  } else {  /* On inside of train.*/

    if(drunk) {
      std::cout << "You: WHOA Buddy, I fink Dis traan is KKRAZY!\n"
                << "Bag Boy: Get out of here you drunk!" << std::endl;
    } else {
      std::cout << "\nYou: So why are you standing here?\n"
                << "Bag Boy: \"Oye! I was the bag boy, until the brake lever of this beast went missing!\n"
                << "Now I am no one's servant! Well, I might be able to help if you make it worth my while.\n"
                << "But until then I am going to get back to enjoying my last few minutes on earth!" << std::endl;
    }
  }

}
