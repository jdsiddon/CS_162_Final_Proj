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
    PassengerCar(int);
    PassengerCar(int, std::string);
    ~PassengerCar();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Bar Car";}

    void chatWithBarTender();

};

#endif
