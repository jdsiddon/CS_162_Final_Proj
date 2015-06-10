#ifndef TRAIN_HPP
#define TRAIN_HPP
#include <string>
#include <deque>

#include "Car.hpp"

class Train {
  private:

  public:
    std::deque<Car*> cars;

    Train();
    ~Train();

    void addCar(int);
    Room* getCurrentCar();
    void listCars();
    //void toggleItemVisibility(std::string);

    Room* getFirstRoom();

    std::deque<Room*> moveOptions(Car*, Room*);
    //Room* remove();
    //void adjacentNodes();

};

#endif
