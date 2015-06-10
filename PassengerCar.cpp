#include <iostream> // Debugging.

#include "Room.hpp"
#include "PassengerCar.hpp"

/*********************************************************************
 ** Function: PassengerCar
 ** Description: Default PassengerCar constructor. Calls Room class
 ** default constructor and makes it an 'outside' room.
 ** Parameters: int roomNumber, room number of the room.
 ** Pre-Conditions: No PassengerCar created.
 ** Post-Conditions: PassengerCar created.
 *********************************************************************/
PassengerCar::PassengerCar(Room *previousCar)
  : Room(previousCar) {
}

/*********************************************************************
 ** Function: PassengerCar
 ** Description: Secondary PassengerCar constructor. Used to create
 ** the left and right ouside portions of the car.
 ** Parameters: int roomNumber, room number of the room. std::string side,
 ** "left" or "right" side of the car.
 ** Pre-Conditions: No PassengerCar created.
 ** Post-Conditions: PassengerCar created.
 *********************************************************************/
PassengerCar::PassengerCar(std::string side, Room *previousCar)
  : Room(side, previousCar) {
}

/*********************************************************************
 ** Function: ~PassengerCar
 ** Description: Default PassengerCar destructor.
 ** Parameters: None.
 ** Pre-Conditions: PassengerCar.
 ** Post-Conditions: PassengerCar object destroyed.
 *********************************************************************/
PassengerCar::~PassengerCar() {

}

/*********************************************************************
 ** Function: getCustomFunction
 ** Description: Returns a breif string describing the custom function
 ** available in the room type.
 ** Parameters: None.
 ** Pre-Conditions: Special function unknown.
 ** Post-Conditions: Special function known.
 *********************************************************************/
std::string PassengerCar::getCustomFunction() {
  return "Take a nap";
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
std::string PassengerCar::customBehavior(std::vector<Item*> items) {
  std::cout << "\n'You take a 30 second cat nap, feeling much better but, "
            << "time is runnining out!'"<< std::endl;
  return "rested";
}

/*********************************************************************
 ** Function: talk
 ** Description: Talks to people in Passenger Car.
 ** Parameters: None.
 ** Pre-Conditions: No talking.
 ** Post-Conditions: Talking action complete.
 *********************************************************************/
void PassengerCar::talk(bool drunk) {
  if(getOutside()) {
    std::cout << "\n'No one in their right mind is on the outside of a train to talk!'\n";

  } else {  /* On inside of train.*/

    if (drunk) {
      std::cout << "\nPassengers: Why don't you take a quick rest so you can get this train under control you drunk!" << std::endl;
    } else {
      std::cout << "\nPassengers: You have to help us! This train is out of control!" << std::endl;
    }
  }
}
