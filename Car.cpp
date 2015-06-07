#include <string>
#include <list>

#include "Car.hpp"
#include "Room.hpp"
#include "BaggageCar.hpp"
#include "BarCar.hpp"
#include "PassengerCar.hpp"


/*********************************************************************
 ** Function: Car
 ** Description: Main car constructor.
 ** Parameters: int number, numeric car identifier.
 ** Pre-Conditions: Car not created.
 ** Post-Conditions: Car created with 3 different rooms attached by
 ** creating three different rooms and adding them to the 'rooms'
 ** list.
 *********************************************************************/
Car::Car(int number) {
  Room *room;
  Room *leftOut;
  Room *rightOut;

  setCarNumber(number);/* Set car number */

  /* DEBUGGING CODE */
  //std::cout << "carNumber: " << carNumber << std::endl;

  /* Create different room types. */
  if(carNumber == 0) {
    leftOut = new BaggageCar("left");
    room = new BaggageCar(); /* MIDDLE ROOM */
    rightOut = new BaggageCar("right");

  } else if (carNumber >= 1 && carNumber <= 2) {
    leftOut = new PassengerCar("left");
    room = new PassengerCar(); /* MIDDLE ROOM */
    rightOut = new PassengerCar("right");

  } else if (carNumber == 3) {
    leftOut = new BarCar("left");
    room = new BarCar();  /* MIDDLE ROOM */
    rightOut = new BarCar("right");

  }

  /* Add room types to rooms list. */
  rooms.push_back(leftOut);
  rooms.push_back(room);  /* Room thats on the 'inside' of the train is in the middle! */
  rooms.push_back(rightOut);

  std::cout << "Rooms Length: " << rooms.size();
}

Car::~Car() {
  for (std::list<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) {
    delete (*it);
    (*it) = 0;
  }

}

void Car::setCarNumber(int number) {
  carNumber = number;
}


/*********************************************************************
 ** Function: getInside
 ** Description: Loops through the rooms of the car and returns the 'inside'
 ** room of the car.
 ** Parameters: None.
 ** Pre-Conditions: No inside room returned.
 ** Post-Conditions: Inside room returned.
 *********************************************************************/
Room* Car::getInside() {
  Room *center; /* Temporary pointer to center of train, 'inside' room. */

  for (std::list<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) { /* Loop through and get center car. */
    if (!(*it)->getOutside()) {     /* Set center to center room. */
      center = *it;

    } else {
      continue;

    }
  }

  return center;
}
