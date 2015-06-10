/*********************************************************************
 ** Program Filename: BarCar.hpp
 ** Author: Justin Siddon
 ** Date: 5/30/15
 ** Description: This file defines the methods of the Room class.
 ** Input: None.
 ** Output: None.
 *********************************************************************/

#ifndef BARCAR_HPP
#define BARCAR_HPP

#include <string>
#include <iostream>

class BarCar : public Room {

  private:

  protected:

  public:
    BarCar(Room*);
    BarCar(std::string, Room*);
    ~BarCar();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Bar Car";}
    std::string getCustomFunction();
    void talk(bool);
    std::string customBehavior(std::vector<Item*>);

};


#endif
