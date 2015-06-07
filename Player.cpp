#include "Player.hpp"

Player::Player() {
  setName("Bob Smith");
  setBagLimit(5);
}

Player::Player(std::string text, Train *train) {
  setName(text); /* Set player name. */

  /* Set first room to where player starts. */
  setCurrentRoom(train->getFirstRoom());

}

void Player::setName(std::string text) {
  name = text;
}

std::string Player::getName() {
  return name;
}

void Player::setBagLimit(int number) {
  bagLimit = number;
}

int Player::getBagLimit() {
  return bagLimit;
}

void Player::setCurrentRoom(Room *tempRoom) {
  currentRoom = tempRoom;
}

Room* Player::getCurrentRoom() {
  return currentRoom;
}
