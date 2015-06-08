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
Car::Car(int number, Car* endCar) {
  Room *room;
  Room *leftOut;
  Room *rightOut;

  setCarNumber(number);/* Set car number */

  /* DEBUGGING CODE */
  //std::cout << "carNumber: " << carNumber << std::endl;

  /* Create different room types. */
  if(carNumber == 0) {  /* Start with the first car pointing to NULL's for 'previous car'. */
    leftOut = new BaggageCar("left", NULL);
    room = new BaggageCar(NULL); /* MIDDLE ROOM */
    rightOut = new BaggageCar("right", NULL);

  } else if (carNumber >= 1 && carNumber <= 2) {
    leftOut = new PassengerCar("left", endCar->getWestOutside());
    room = new PassengerCar(endCar->getWestOutside()); /* MIDDLE ROOM */
    rightOut = new PassengerCar("right", endCar->getWestOutside());

  } else if (carNumber == 3) {
    leftOut = new BarCar("left", endCar->getWestOutside());
    room = new BarCar(endCar->getWestOutside());  /* MIDDLE ROOM */
    rightOut = new BarCar("right", endCar->getWestOutside());

  }

  /* Add east and west connections to the new rooms. */
  leftOut->setEast(room);
  leftOut->setWest(NULL);

  room->setWest(leftOut);
  room->setEast(rightOut);

  rightOut->setWest(room);
  rightOut->setEast(NULL);

  /* Add room types to rooms list. */
  rooms.push_back(leftOut);
  rooms.push_back(room);  /* Room thats on the 'inside' of the train is in the middle! */
  rooms.push_back(rightOut);

  /* DEBUGGING CODE */
  //std::cout << "Rooms Length: " << rooms.size();
  std::cout << "Room Connections " << std::endl;
  std::cout << "Inside: " << std::endl;
  std::cout << "- East: " << room->getEast()->getOutside() << ", " << room->getEast()->getTrainSide() << std::endl;
  std::cout << "- West: " << room->getWest()->getOutside() << ", " << room->getWest()->getTrainSide() << std::endl;

  std::cout << "Left: " << std::endl;
  std::cout << "- East: " << leftOut->getEast() << ", " << leftOut->getEast() << std::endl;
  std::cout << "- West: " << leftOut->getWest() << ", " << leftOut->getWest() << std::endl;

  std::cout << "Right: " << std::endl;
  std::cout << "- East: " << rightOut->getEast() << ", " << rightOut->getEast() << std::endl;
  std::cout << "- West: " << rightOut->getWest() << ", " << rightOut->getWest() << std::endl;
}

Car::~Car() {
  for (std::deque<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) {
    delete (*it);
    (*it) = 0;
  }

}

void Car::setCarNumber(int number) {
  carNumber = number;
}

int Car::getCarNumber() {
  return carNumber;
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

  for (std::deque<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) { /* Loop through and get center car. */
    if (!(*it)->getOutside()) {     /* Set center to center room. */
      center = *it;

    } else {
      continue;

    }
  }

  return center;
}

/*********************************************************************
 ** Function: getEastOutside
 ** Description: Returns the first element in rooms list. West, Inside, East.
 ** Parameters: None.
 ** Pre-Conditions: No inside room returned.
 ** Post-Conditions: Inside room returned.
 *********************************************************************/
Room* Car::getEastOutside() {
  return rooms.back(); /* Return the first room because that is the outside east. */
}

/*********************************************************************
 ** Function: getWestOutside
 ** Description: Returns the last element in rooms list. West, Inside, East.
 ** Parameters: None.
 ** Pre-Conditions: No inside room returned.
 ** Post-Conditions: Inside room returned.
 *********************************************************************/
Room* Car::getWestOutside() {
  if(!rooms.empty())
    return rooms.front(); /* Return the first room because that is the outside east. */
  else
    return NULL;
}
