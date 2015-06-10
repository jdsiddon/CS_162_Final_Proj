#ifndef CAR_HPP
#define CAR_HPP

#include <string>
#include <list>

#include "Room.hpp"
#include "BarCar.hpp"
#include "BaggageCar.hpp"
#include "PassengerCar.hpp"

class Car {
  private:
    Car* previousCar;
    Car* nextCar;
    int carNumber;
    std::deque<Room*> rooms;

  public:
    Car(int, Car*);
    ~Car();
    void setCarNumber(int);
    int getCarNumber();
    Room* getInside();

    Room* getEastOutside();
    Room* getWestOutside();
    void distributeItems();

};

#endif
