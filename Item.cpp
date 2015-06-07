#include "Item.hpp"

Item::Item() {
  setName(" ");
}

Item::Item(std::string tempName) {
  setName(tempName);
}

void Item::setName(std::string text) {
  name = text;
}

std::string Item::getName() {
  return name;
}
