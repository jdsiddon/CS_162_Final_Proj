#include "Player.hpp"

Player::Player() {
  setName("Bob Smith");
  setBagLimit(5);
}

Player::Player(std::string text) {
  setName(text);
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
