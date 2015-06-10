#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <string>
#include <deque>

#include "Car.hpp"

class Train {
  private:
    std::deque<Car*> cars;

  public:
    Train();
    ~Train();
    void addCar(int);
    Room* getCurrentCar();
    Room* getFirstRoom();

    /* DEBUGGING METHODS */
    void listCars();

};

#endif
