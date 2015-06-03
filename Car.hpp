#ifndef CAR_HPP
#define CAR_HPP
#include <string>
#include <list>

#include "Room.hpp"
#include "BarCar.hpp"
#include "PassengerCar.hpp"
#include "BaggageCar.hpp"

class Car {
  private:


  public:
    std::list<Room*> rooms;
    Car(int);
    Room* getCurrentRoom();
    //Room* remove();
    //void adjacentNodes();

};

#endif
