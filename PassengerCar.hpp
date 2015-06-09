/*********************************************************************
 ** Program Filename: PassengerCar.hpp
 ** Author: Justin Siddon
 ** Date: 5/30/15
 ** Description: This file defines the methods of the Room class.
 ** Input: None.
 ** Output: None.
 *********************************************************************/

#ifndef PASSENGERCAR_HPP
#define PASSENGERCAR_HPP

#include <string>
#include <iostream>

class PassengerCar : public Room {

  private:

  protected:

  public:
    PassengerCar(Room*);
    PassengerCar(std::string, Room*);
    ~PassengerCar();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Passenger Car";}

    virtual std::string getCustomFunction();
    void talk();
    void customBehavior(std::string);

};

#endif
