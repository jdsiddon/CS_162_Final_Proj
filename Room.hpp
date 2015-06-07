/*********************************************************************
 ** Program Filename: Room.hpp
 ** Author: Justin Siddon
 ** Date: 5/30/15
 ** Description: This file defines the methods of the Room class.
 ** Input: None.
 ** Output: None.
 *********************************************************************/

#ifndef ROOM_HPP
#define ROOM_HPP

#include <string>
#include <iostream>

class Room {

  private:
    bool outside;
    std::string trainSide;

  protected:
    void setOutside(bool);
    void setTrainSide(std::string = NULL);

  public:
    Room();
    Room(std::string);
    virtual ~Room();

    /* Getters */
    bool getOutside();
    std::string getTrainSide();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Room"; }

};


#endif
