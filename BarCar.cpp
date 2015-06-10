#include <iostream> // Debugging.

#include "Room.hpp"
#include "BarCar.hpp"


/*********************************************************************
 ** Function: BarCar
 ** Description: Default BarCar constructor. Calls Room class
 ** default constructor and makes it an 'outside' room.
 ** Parameters: int roomNumber, room number of the room.
 ** Pre-Conditions: No BarCar created.
 ** Post-Conditions: BarCar created.
 *********************************************************************/
BarCar::BarCar(Room *previousCar)
  : Room(previousCar) {
}

/*********************************************************************
 ** Function: BarCar
 ** Description: Secondary BarCar constructor. Used to create
 ** the left and right ouside portions of the car.
 ** Parameters: int roomNumber, room number of the room. std::string side,
 ** "left" or "right" side of the car.
 ** Pre-Conditions: No BarCar created.
 ** Post-Conditions: BarCar created.
 *********************************************************************/
BarCar::BarCar(std::string side, Room *previousCar)
  : Room(side, previousCar) {
}

/*********************************************************************
 ** Function: ~BarCar
 ** Description: Default BarCar destructor.
 ** Parameters: None.
 ** Pre-Conditions: BarCar.
 ** Post-Conditions: BarCar object destroyed.
 *********************************************************************/
BarCar::~BarCar() {

}

/*********************************************************************
 ** Function: getCustomFunction
 ** Description: Returns a breif string describing the custom function
 ** available in the room type.
 ** Parameters: None.
 ** Pre-Conditions: Special function unknown.
 ** Post-Conditions: Special function known.
 *********************************************************************/
std::string BarCar::getCustomFunction() {
  return "Have a drink";
}

/*********************************************************************
 ** Function: customBehavior
 ** Description: Allows player to take a nap and recover from being drunk
 ** but also take 30 seconds off of the amount of time available before the
 ** train flys of the tracks!
 ** Parameters: vector<Item*> items, items the player has at their
 ** disposal if needed.
 ** Pre-Conditions: Special function unknown.
 ** Post-Conditions: Special function known.
 *********************************************************************/
std::string BarCar::customBehavior(std::vector<Item*> tempItems) {
  Item *item1 = NULL;

  /* Check to see if 'glass' are in the players bag of items. */
  for(int i = 0; i < tempItems.size(); i++) {
    //std::cout << bagOfItems[i]->getName();

    if(tempItems[i]->getName() == "glass") {
      item1 = tempItems[i];
      tempItems.erase(tempItems.begin() + i); /* Remove item from the players bag. */

      break;  /* Only need a single glass. */
    }
  }

  std::cout << "\n";
  if (item1) {    /* Found a glass so we can have a drink. */
    std::cout << "You: Here sir I found you a glass.\n"
              << "Bar Tender: \"Thanks for the glass!\n"
              << "Here enjoy the drink! You know I found some weird looking handle thing"
              << "a while back I would check the train again I know its around here somewhere."<< std::endl;

    /* Toggle coins visible */
    for(int i = 0; i < items.size(); i++) {
      if(items[i]->getName() == "brake lever") {
        items[i]->setVisible(true);
      }
    }
    std::cout << "\n'Had more than a few drinks. Not feeling so sharp'" << std::endl;

  } else {
    std::cout << "Bar Tender: Come later maybe by then I will have found a glass to serve you." << std::endl;
  }

  return "drunk";
}

/*********************************************************************
 ** Function: talk
 ** Description: Talks to people in Bar Car.
 ** Parameters: bool sober, false if user is drunk, true if sober.
 ** Pre-Conditions: No talking.
 ** Post-Conditions: Talking action complete.
 *********************************************************************/
void BarCar::talk(bool sober) {
  if (!sober) {  /* Check to see if player is drunk. */
    std::cout << "\nYou: Heee YaaH! Whose Ridding heeer anywhoooo?!\n"
              << "Bar Tender: You sir are cut off until you get some rest..." << std::endl;
  } else {
    std::cout << "\nYou: Notice anything weird around here?\n"
              << "Bar Tender: Yea glasses keep going missing. If I got one or two\n"
              << "back I might be able to remember something." << std::endl;

  }

}
