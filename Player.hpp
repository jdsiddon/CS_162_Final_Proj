#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

#include "Item.hpp"

class Player {

  private:
    std::string name;
    void setName(std::string);
    std::vector<Item> bag;

  public:
    Player();
    Player(std::string);
    std::string getName();
    // Room* getCurrentRoom();
    // Room* currentRoom();

};

#endif
