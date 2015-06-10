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

    /* Room connectors */
    Room* eastRoom;
    Room* westRoom;
    Room* northRoom;
    Room* southRoom;


  protected:
    void setOutside(bool);
    void setTrainSide(std::string = NULL);
    enum Side {east, west};
    Side trainSide;
    std::vector<Item*> items;

  public:
    Room(Room*);
    Room(std::string, Room*); //Add set previous

    void setEast(Room*);
    void setWest(Room*);
    void setNorth(Room*);
    void setSouth(Room*);

    Room* getCurrent();
    Room* getEast();
    Room* getWest();
    Room* getNorth();
    Room* getSouth();

    virtual ~Room();
    virtual void talk(bool) { }
    Item* search();

    /* Getters */
    bool getOutside();
    std::string getTrainSide();
    Room* moveMenu();

    void addItem(std::string);
    int getRoomOptions();
    int printItems();
    Item* takeItem();

    /* Virtual methods defined in each sub-class. */
    virtual std::string getCustomFunction() { return " "; }
    virtual std::string customBehavior(std::vector<Item*>) { return " "; }
    virtual const char* getRoomType() { return "Room"; }

};


#endif
