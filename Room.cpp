#include "Room.hpp"

Room::Room() {
  setOutside(true);
}

Room::Room(int number) {
  setRoomNumber(number);
  setOutside(false);
}

Room::~Room() {

}


int Room::getRoomNumber() {
  return roomNumber;
}


void Room::setRoomNumber(int number) {
  roomNumber = number;
}


void Room::setOutside(bool value) {
  outside = value;
}

bool Room::getOutside() {
  return outside;
}
