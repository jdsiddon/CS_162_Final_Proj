#include "Item.hpp"

Item::Item() {
  setName(" ");
  setVisible(true);
}

Item::Item(std::string tempName) {
  setName(tempName);

  if (tempName == "glass" || tempName == "brake lever") { /* If coins or brake lever, set to invisible. */
    this->setVisible(false);

  } else {
    this->setVisible(true);

  }

}

void Item::setName(std::string text) {
  name = text;
}

std::string Item::getName() {
  return name;
}

void Item::setVisible(bool vis) {
  visible = vis;
}

bool Item::getVisible() {
  return visible;
}
