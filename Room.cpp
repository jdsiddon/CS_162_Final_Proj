#include "Room.hpp"

Room::Room(Room* previousCar) {
  setTrainSide("inside");
  setOutside(false);

  if(previousCar != NULL) { /* If previousCar is NULL, we are on the end of the train. */
    /* Connect new room to last old last room. */
    setSouth(previousCar);

    /* Set previous car's north to the new room. */
    previousCar->setNorth(this);
  }
}

Room::Room(std::string side, Room* previousCar) {
  setOutside(true); /* Make room on the outside. */
  setTrainSide(side); /* Set the side */

  if(previousCar != NULL) { /* If previousCar is NULL, we are on the end of the train. */
    /* Connect new room to last old last room. */
    setSouth(previousCar);

    /* Set previous car's north to the new room. */
    previousCar->setNorth(this);
  }
}

Room::~Room() {

}

/* Set if the room is outside. */
void Room::setOutside(bool value) {
  outside = value;
}

/* Returns if the room is outside. */
/* Returns false if the room is inside. */
bool Room::getOutside() {
  return outside;
}

/* Set the side of the train the room is on. */
void Room::setTrainSide(std::string text) {
  trainSide = text;
}

/* Gets the side of the train the room is on. */
std::string Room::getTrainSide() {
  return trainSide;
}


void Room::printRoomMenu() {
  int selection = 0;

  while (selection != 1 || selection != 2) {
    std::cout << "1. Look for items\n"
              << "2. Move" << std::endl;

    std::cin >> selection;
  }

  //return selection;
}

void Room::setSouth(Room* previousRoom) {
  southRoom = previousRoom;
}

void Room::setNorth(Room* nextRoom) {
  northRoom = nextRoom;
}

void Room::setEast(Room* sideRoom) {
  eastRoom = sideRoom;
}

void Room::setWest(Room* sideRoom) {
  westRoom = sideRoom;
}

Room* Room::getSouth() {
  return this->southRoom;
}

Room* Room::getNorth() {
  return this->northRoom;
}

Room* Room::getEast() {
  return this->eastRoom;
}

Room* Room::getWest() {
  return this->westRoom;
}
