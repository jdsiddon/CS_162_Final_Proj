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

std::string BarCar::getCustomFunction() {
  return "Have a drink";
}

void BarCar::customBehavior(std::string name) {
  std::cout << "Custom bar";
}

/*********************************************************************
 ** Function: talk
 ** Description: Talks to people in Bar Car.
 ** Parameters: None.
 ** Pre-Conditions: No talking.
 ** Post-Conditions: Talking action complete.
 *********************************************************************/
void BarCar::talk() {
  std::cout << "Want a drink?" << std::endl;
}
