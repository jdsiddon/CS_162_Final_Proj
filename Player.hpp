#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

#include "Item.hpp"

class Player {

  private:
    std::string name;
    void setName(std::string);
    void setBagLimit(int);
    std::vector<Item> bag;
    int bagLimit;

  public:
    Player();
    Player(std::string);
    std::string getName();
    int getBagLimit();

    // Room* getCurrentRoom();
    // Room* currentRoom();

};

#endif
