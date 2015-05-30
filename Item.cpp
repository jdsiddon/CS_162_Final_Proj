#include "Item.hpp"

Item::Item() {

}

Item::Item(std::string tempName) {

}

void Item::setName(std::string text) {
  name = text;
}

std::string Item::getName() {
  return name;
}
