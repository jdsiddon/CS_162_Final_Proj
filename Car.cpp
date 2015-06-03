#include <string>
#include <list>

#include "Car.hpp"


Car::Car(int roomNumber) {
  roomNumber = 3;
  Room *room;
  Room *leftOut;
  Room *rightOut;

  //std::string type = room1->getRoomType();  /* Get room type. */

  if(roomNumber == 0) {
    room = new BaggageCar(roomNumber);
    Room *leftOut = new BaggageCar(false, "left");
    Room *rightOut = new BaggageCar(false, "right");

  } else if (roomNumber >= 1 || roomNumber <= 2) {
    room = new PassengerCar(roomNumber);
    Room *leftOut = new PassengerCar(false, "left");
    Room *rightOut = new PassengerCar(false, "right");

  } else if (roomNumber == 3) {
    room = new BarCar(roomNumber);
    leftOut = new BarCar(roomNumber, "left");
    rightOut = new BarCar(roomNumber, "right");

  }

  rooms.push_back(room);
  rooms.push_back(leftOut);
  rooms.push_back(rightOut);
}

Room* Car::getCurrentRoom() {

}
