#include "Room.hpp"

Room::Room(int number) {
  setRoomNumber(number);
}

Room::~Room() {

}


int Room::getRoomNumber() {
  return roomNumber;
}


void Room::setRoomNumber(int number) {
  roomNumber = number;
}
