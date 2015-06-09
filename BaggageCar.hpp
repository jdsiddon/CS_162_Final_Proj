/*********************************************************************
 ** Program Filename: BaggageCar.hpp
 ** Author: Justin Siddon
 ** Date: 5/30/15
 ** Description: This file defines the methods of the Room class.
 ** Input: None.
 ** Output: None.
 *********************************************************************/

#ifndef BAGGAGECAR_HPP
#define BAGGAGECAR_HPP

#include <string>
#include <iostream>

class BaggageCar : public Room {

  private:

  protected:

  public:
    BaggageCar(Room*);
    BaggageCar(std::string, Room*);
    ~BaggageCar();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Baggage Car";}

    std::string getCustomFunction();
    void talk();
    void customBehavior(std::vector<Item*>);

};


#endif
