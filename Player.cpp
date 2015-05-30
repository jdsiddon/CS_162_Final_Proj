#include "Player.hpp"

Player::Player() {
  setName("Bob Smith");
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
