#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <string>
#include <list>

#include "Car.hpp"

class Train {
  private:

  public:
    std::list<Car*> cars;

    Train();
    ~Train();

    void addCar(int);
    Room* getCurrentCar();
    void listCars();

    Room* getFirstRoom();
    //Room* remove();
    //void adjacentNodes();

};

#endif
