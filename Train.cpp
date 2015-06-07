#include "Train.hpp"
#include "Car.hpp"

#define TRAIN_LENGTH 4

/*********************************************************************
 ** Function: Train
 ** Description: Default train constructor, creates the train
 ** by calling 'addCar' based on the set train length.
 ** Parameters: None.
 ** Pre-Conditions: No train created.
 ** Post-Conditions: Train created with as many cars as equal to 'TRAIN_LENGTH'.
 *********************************************************************/
Train::Train() {
  for(int i = 0; i < TRAIN_LENGTH; i++) {
    addCar(i);  /* Add car to train. */
  }

}

/*********************************************************************
 ** Function: ~Train
 ** Description: Train destructor. Calls Car destructor for each car
 ** in the train.
 ** Parameters: None.
 ** Pre-Conditions: Train still created.
 ** Post-Conditions: Train cars deleted.
 *********************************************************************/
Train::~Train() {
  for (std::list<Car*>::iterator it = cars.begin(); it != cars.end(); ++it) {
    delete (*it);
    (*it) = 0;
  }

}


/*********************************************************************
 ** Function: addCar
 ** Description: Adds a car to the train.
 ** Parameters: int carNumber, car number to add to the train.
 ** Pre-Conditions: Car not added to train.
 ** Post-Conditions: Car added to the 'cars' list in the Train object.
 *********************************************************************/
void Train::addCar(int carNumber) {
  Car *car1 = new Car(carNumber);   /* Create new car. */
  cars.push_back(car1);             /* Add car to cars vector. */
}


/*********************************************************************
 ** Function: listCars
 ** Description: Lists cars on the train. Prints out a list of
 ** inside the train rooms.
 ** Parameters: None.
 ** Pre-Conditions: Cars not listed.
 ** Post-Conditions: Cars listed.
 *********************************************************************/
void Train::listCars() {
  /* DEBUGGING CODE */
  // std::cout << cars.size() << std::endl;
  for (std::list<Car*>::const_iterator it = cars.begin(); it != cars.end(); ++it) {
    /* Get the inside train room and print out the type of car its in. */
    std::cout << (*it)->getInside()->getRoomType() << std::endl;  /* Only return the 'inside' room of the car. */
  }
}
