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
#include <deque>
#include <iostream>

#include "Item.hpp"

class Room {

  private:
    bool outside;
    std::string trainSide;
    std::deque<Item*> items;

    /* Room connectors */
    Room* eastRoom;
    Room* westRoom;
    Room* northRoom;
    Room* southRoom;


  protected:
    void setOutside(bool);
    void setTrainSide(std::string = NULL);

  public:
    Room(Room*);
    Room(std::string, Room*); //Add set previous

    void setEast(Room*);
    void setWest(Room*);
    void setNorth(Room*);
    void setSouth(Room*);

    Room* getEast();
    Room* getWest();
    Room* getNorth();
    Room* getSouth();


    virtual ~Room();

    /* Getters */
    bool getOutside();
    std::string getTrainSide();
    void printRoomMenu();

    /* Virtual methods defined in each sub-class. */
    virtual const char* getRoomType() { return "Room"; }

};


#endif
