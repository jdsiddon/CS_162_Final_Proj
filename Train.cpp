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
  for (std::deque<Car*>::iterator it = cars.begin(); it != cars.end(); ++it) {
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
  Car *previousEndCar = NULL;

  if(!cars.empty()) {
    previousEndCar = cars.back(); /* Get the car that used to be the end. */
  }

  Car *car1 = new Car(carNumber, previousEndCar);   /* Create new car, pass the previously 'end'
                                                       car to the constructor. */

  cars.push_back(car1);             /* Add car to cars vector. */
}

/*********************************************************************
 ** Function: generateItems
 ** Description: Generates items that will be on the train. Items then
 ** get distributed throughout the train.
 ** Parameters: None.
 ** Pre-Conditions: Items not created.
 ** Post-Conditions: Adds items to items vector.
 *********************************************************************/
//void Train::generateItems() {
  // Item *brakeLever = new Item("Brake Lever");   /* Create new Item. */
  // Item *hat = new Item("Hat");   /* Create new Item. */
  // Item *key = new Item("Key");   /* Create new Item. */
  // Item *coins = new Item("Coins");   /* Create new Item. */
  // items.push_back(brakeLever);             /* Add car to cars vector. */
  // items.push_back(hat);             /* Add car to cars vector. */
  // items.push_back(key);             /* Add car to cars vector. */
  // items.push_back(coins);             /* Add car to cars vector. */
//}


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
  std::cout << "Welcome abord!" << std::endl;
  std::deque<Car*>::iterator it = cars.begin();
  //
  while(it != cars.end()) {
    /* Get the inside train room and print out the type of car its in. */
    std::cout << " - " << (*it)->getInside()->getRoomType() << std::endl;  /* Only return the 'inside' room of the car. */
    it++;
  }
}

/*********************************************************************
 ** Function: getFirstRoom
 ** Description: Returns the first room in the car.
 ** Parameters: None.
 ** Pre-Conditions: Cars not listed.
 ** Post-Conditions: Cars listed.
 *********************************************************************/
Room* Train::getFirstRoom() {
  /* Return the 'inside' room from the first car in the train. */
  return cars.front()->getInside();
}

/* Returns Options for movement to the user based on the car and room they are in. */
std::deque<Room*> Train::moveOptions(Car*, Room*) {


}

/*********************************************************************
 ** Function: toggleItemVisibility
 ** Description: Sets each item with the name equal to the passed string
 ** to visible, so users can see the item and pick it up.
 ** Parameters: string name, name of the item to toggle to visible.
 ** Pre-Conditions: Items in train with the same name invisible.
 ** Post-Conditions: Items in train with the same name visible.
 *********************************************************************/
// void Train::toggleItemVisibility(std::string name) {
//   std::deque<Car*>::iterator car = cars.begin();
//
//   /* Loop through cars in the train. */
//   while(car != cars.end()) {
//     /* Loop through rooms in car. */
//     for (std::deque<Room*>::iterator room = (*car)->rooms.begin(); room != (*car)->rooms.end(); ++room) {
//       (*room)->getRoomType(); /* Print out rooms. */
//     }
//
//     car++;
//   }
// }
