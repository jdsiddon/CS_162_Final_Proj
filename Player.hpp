#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

#include "Train.hpp"
#include "Room.hpp"
#include "Item.hpp"

class Player {

  private:
    std::string name;
    void setName(std::string);
    void setBagLimit(int);
    std::vector<Item> bag;
    int bagLimit;
    Room *currentRoom;



  public:
    Player();
    Player(std::string, Train*);
    std::string getName();
    int getBagLimit();

    Room* getCurrentRoom();
    void setCurrentRoom(Room*);
    
    // Room* currentRoom();

};

#endif
