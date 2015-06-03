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
    int roomNumber;
    bool outside;
    void setRoomNumber(int);
    void setOutside(bool);

  protected:

  public:
    Room();
    Room(int);
    virtual ~Room();

    /* Getters */
    int getRoomNumber();
    bool getOutside();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Room";}

};


#endif
