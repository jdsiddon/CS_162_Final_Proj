#include "Room.hpp"

Room::Room(int number) {
  setRoomNumber(number);
  setOutside(false);
}

Room::Room(int number, std::string side) {
  setRoomNumber(number);
  setOutside(true);
  setTrainSide(side);
}

Room::~Room() {

}


/* Return the room number of the room. */
int Room::getRoomNumber() {
  return roomNumber;
}

/* Set the room number of the room. */
void Room::setRoomNumber(int number) {
  roomNumber = number;
}

/* Set if the room is outside. */
void Room::setOutside(bool value) {
  outside = value;
}

/* Returns if the room is outside. */
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
