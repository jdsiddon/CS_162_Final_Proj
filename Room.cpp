#include "Room.hpp"

Room::Room() {
  setTrainSide("inside");
  setOutside(false);
}

Room::Room(std::string side) {
  setOutside(true);
  setTrainSide(side);
}

Room::~Room() {

}

/* Set if the room is outside. */
void Room::setOutside(bool value) {
  outside = value;
}

/* Returns if the room is outside. */
/* Returns false if the room is inside. */
bool Room::getOutside() {
  return outside;
}

/* Set the side of the train the room is on. */
void Room::setTrainSide(std::string text) {
  trainSide = text;
}

/* Gets the side of the train the room is on. */
std::string Room::getTrainSide() {
  return trainSide;
}
