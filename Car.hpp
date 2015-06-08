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
    Car* previousCar;
    Car* nextCar;

    int carNumber;

  public:
    std::deque<Room*> rooms;
    Car(int, Car*);
    ~Car();
    void setCarNumber(int);
    int getCarNumber();
    Room* getInside();

    Room* getEastOutside();
    Room* getWestOutside();
    //void setRoomInCar(Room*);
    //Room* remove();
    //void adjacentNodes();

};

#endif
