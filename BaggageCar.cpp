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
 ** Function: talk
 ** Description: Talks to people in Bagger Car.
 ** Parameters: None.
 ** Pre-Conditions: No talking.
 ** Post-Conditions: Talking action complete.
 *********************************************************************/
void BaggageCar::talk() {
  std::cout << "Oye! I am the bag man!" << std::endl;
}

/*********************************************************************
 ** Function: search
 ** Description: Searches for items in Bagger Car.
 ** Parameters: None.
 ** Pre-Conditions: No searching.
 ** Post-Conditions: Searching action complete.
 *********************************************************************/
void BaggageCar::search() {
  std::cout << "Searching through luggage!" << std::endl;
}
