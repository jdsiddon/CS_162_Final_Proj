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
    int carNumber;

  public:
    std::deque<Room*> rooms;
    Car(int);
    ~Car();
    void setCarNumber(int);
    Room* getInside();
    //void setRoomInCar(Room*);
    //Room* remove();
    //void adjacentNodes();

};

#endif
