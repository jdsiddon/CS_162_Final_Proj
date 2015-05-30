#include <iostream>
#include <string>

#include "Room.hpp"

Room::Room() {

}

Room::~Room() {

}


std::string Room::getRoomNumber() {
  return "getRoomNumber";
}


void Room::setRoomNumber(int number) {
  roomNumber = number;
}
