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
PassengerCar::PassengerCar()
  : Room() {
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
PassengerCar::PassengerCar(std::string side)
  : Room(side) {
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
 ** Function: chatWithBarTender
 ** Description: .
 ** Parameters: None.
 ** Pre-Conditions: .
 ** Post-Conditions: .
 *********************************************************************/
void PassengerCar::chatWithBarTender() {

}
