#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <vector>
#include <string>

#include "Train.hpp"
#include "Car.hpp"
#include "Room.hpp"
#include "Item.hpp"

class Player {

  private:
    std::string name;
    void setName(std::string);
    void setBagLimit(int);
    std::vector<Item*> bag;
    int bagLimit;
    Room *currentRoom;
    Car *currentCar;

    bool sobriety;

  public:
    Player();
    Player(std::string, Train*);
    std::string getName();
    Item* getItem(std::string);
    int getBagLimit();

    bool getSobriety();
    void setSobriety(bool);

    void addToBag(Item*);


    Room* getCurrentRoom();
    void setCurrentRoom(Room*);

    Car* getCurrentCar();
    void setCurrentCar(Car*);

    std::vector<Item*> getBagItems();

    // Room* currentRoom();

};

#endif
