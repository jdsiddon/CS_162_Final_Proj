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
BaggageCar::BaggageCar(int roomNumber)
  : Room(roomNumber) {
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
BaggageCar::BaggageCar(int roomNumber, std::string side)
  : Room(roomNumber, side) {
}

/*********************************************************************
 ** Function: ~BaggageCar
 ** Description: Default BaggageCar destructor.
 ** Parameters: None.
 ** Pre-Conditions: BaggageCar.
 ** Post-Conditions: BaggageCar object destroyed.
 *********************************************************************/
BaggageCar::~BaggageCar() {

}


/*********************************************************************
 ** Function: chatWithBarTender
 ** Description: .
 ** Parameters: None.
 ** Pre-Conditions: .
 ** Post-Conditions: .
 *********************************************************************/
void BaggageCar::chatWithBarTender() {

}
