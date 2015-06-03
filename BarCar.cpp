#include <iostream> // Debugging.

#include "Room.hpp"
#include "BarCar.hpp"


/*********************************************************************
 ** Function: BlueMen
 ** Description: Default BarCar constructor. Calls Room class
 ** default constructor and makes it an 'outside' room.
 ** Parameters: None.
 ** Pre-Conditions: No BlueMen created.
 ** Post-Conditions: BlueMen created.
 *********************************************************************/
BarCar::BarCar()
  : Room() {
}

/*********************************************************************
 ** Function: BlueMen
 ** Description: Default BlueMen constructor. Calls Character class
 ** default constructor.
 ** Parameters: None.
 ** Pre-Conditions: No BlueMen created.
 ** Post-Conditions: BlueMen created.
 *********************************************************************/
BarCar::BarCar(int roomNumber)
  : Room(roomNumber) {
}

/*********************************************************************
 ** Function: BlueMen
 ** Description: Default BlueMen destructor.
 ** Parameters: None.
 ** Pre-Conditions: BlueMen.
 ** Post-Conditions: BlueMen object destroyed.
 *********************************************************************/
BarCar::~BarCar() {

}


/*********************************************************************
 ** Function: chatWithBarTender
 ** Description: Default BlueMen destructor.
 ** Parameters: None.
 ** Pre-Conditions: BlueMen.
 ** Post-Conditions: BlueMen object destroyed.
 *********************************************************************/
void BarCar::chatWithBarTender() {

}
