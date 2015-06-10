#include <string.h>
#include <list>

#include "Car.hpp"

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
  Room *west;
  Room *east;

  setCarNumber(number);/* Set car number */

  /* DEBUGGING CODE */
  //std::cout << "carNumber: " << carNumber << std::endl;

  /* Create different room types. */
  if(carNumber == 0) {  /* First car. */
    /* Start with the first car pointing to NULL's for 'previous car'. */
    west = new BaggageCar("west", NULL);
    room = new BaggageCar(NULL); /* MIDDLE ROOM */
    east = new BaggageCar("east", NULL);

  } else if (carNumber >= 1 && carNumber <= 2) {
    west = new PassengerCar("west", endCar->getWestOutside());
    room = new PassengerCar(endCar->getInside()); /* MIDDLE ROOM */
    east = new PassengerCar("east", endCar->getEastOutside());

  } else if (carNumber == 3) {
    west = new BarCar("west", endCar->getWestOutside());
    room = new BarCar(endCar->getInside());  /* MIDDLE ROOM */
    east = new BarCar("east", endCar->getEastOutside());

  }

  /* Add east and west connections to the new rooms. */
  west->setEast(room);
  west->setWest(NULL);

  room->setWest(west);
  room->setEast(east);

  east->setWest(room);
  east->setEast(NULL);

  /* Add room types to rooms list. */
  rooms.push_back(west);
  rooms.push_back(room);  /* Room thats on the 'inside' of the train is in the middle! */
  rooms.push_back(east);

  /* Distribute items between inside and outside rooms. */
  distributeItems();


  /* DEBUGGING CODE */
  // std::cout << "Rooms Length: " << rooms.size();
  // std::cout << "Room Connections " << std::endl;
  // std::cout << "Room: " << room << std::endl;
  // std::cout << "- East: " << room->getEast()->getOutside() << ", " << room->getEast()->getTrainSide() << std::endl;
  // std::cout << "- West: " << room->getWest()->getOutside() << ", " << room->getWest()->getTrainSide() << std::endl;
  // std::cout << "- North: " << room->getNorth() << ", " << room->getNorth() << std::endl;
  // std::cout << "- South: " << room->getSouth() << ", " << room->getSouth() << std::endl;
  //
  // std::cout << "West: " << west << std::endl;
  // std::cout << "- East: " << west->getEast() << ", " << west->getEast() << std::endl;
  // std::cout << "- West: " << west->getWest() << ", " << west->getWest() << std::endl;
  // std::cout << "- North: " << west->getNorth() << ", " << west->getNorth() << std::endl;
  // std::cout << "- South: " << west->getSouth() << ", " << west->getSouth() << std::endl;
  //
  // std::cout << "East: " << east << std::endl;
  // std::cout << "- East: " << east->getEast() << ", " << east->getEast() << std::endl;
  // std::cout << "- West: " << east->getWest() << ", " << east->getWest() << std::endl;
  // std::cout << "- North: " << east->getNorth() << ", " << east->getNorth() << std::endl;
  // std::cout << "- South: " << east->getSouth() << ", " << east->getSouth() << std::endl;
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

/*********************************************************************
 ** Function: distributeItems
 ** Description: Distributes items amoung the 3 rooms of a car (2 inside rooms, 1 outside)
 ** Parameters: None.
 ** Pre-Conditions: Items not in rooms.
 ** Post-Conditions: Items entered into rooms of the car.
 *********************************************************************/
void Car::distributeItems() {
  std::vector<std::string> itemsToDistribute; /* Temporary vector to hold stuff to be distributed between rooms. */
  Dice *coin = new Dice();   /* Create a coin to flip to see if item gets added to room or not. */
  /* DEBUGGIN CODE */
  // std::cout << getInside()->getRoomType() << std::endl;

  /* Set up items in each room based on room type. */
  if(strcmp(getInside()->getRoomType(), "Bar Car") == 0) {
    itemsToDistribute.push_back("coin");

  } else if(strcmp(getInside()->getRoomType(), "Passenger Car") == 0) {
    itemsToDistribute.push_back("glass");

  } else if(strcmp(getInside()->getRoomType(), "Baggage Car") == 0) {
    itemsToDistribute.push_back("action figure");
    itemsToDistribute.push_back("brake lever");

  }

  /* Distribute items between inside and outside rooms. */
  while (!itemsToDistribute.empty()) {      /* Loop through items to distribute while the temp array isn't empty. */
    for (std::deque<Room*>::iterator it = rooms.begin(); it != rooms.end(); ++it) { /* Loop through rooms in car. */

      /* Check again if items vector is empty, if there is less than three items
         in the vector then the for loop through the rooms will break. */
      if(itemsToDistribute.empty()) {
        break;

      } else {  /* Still have items in vector. */
        int result = coin->rollDice();

        if (result >= 2) {   /* Heads, add item to room. */
          /* DEBUGGING CODE */
          // std::cout << "Adding" << std::endl;
          // std::cout << (*it)->getRoomType() << std::endl;
          // std::cout << "Item: " << itemsToDistribute.back() << std::endl;
          (*it)->addItem(itemsToDistribute.back()); /* Add item to room. */
          itemsToDistribute.pop_back();             /* Remove item from temp vector. */
        }

      }

    }

  }

  /* Delete dice pointer. */
  delete coin;
  coin = 0;

}
