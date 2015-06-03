#include "Train.hpp"
#include "Car.hpp"

#define TRAIN_LENGTH 4

Train::Train() {
  for(int i = 0; i < TRAIN_LENGTH; i++) {
    // Add car to train.
    this->addCar(i);
  }

}



/*********************************************************************
 ** Function: add
 ** Description: Adds a value to the queue.
 ** Parameters: Room value, room on the train to add to train.
 ** Room leftValue, 'room' on the outside of the train to link to the
 ** train room. Room rightValue, 'room' on the inside of the train
 ** to link to the train room.
 ** Pre-Conditions: Value not added to queue.
 ** Post-Conditions: Value added to queue.
 *********************************************************************/
void Train::addCar(int carNumber) {
  Car *car1 = new Car(carNumber);
  cars.push_back(car1);
}
