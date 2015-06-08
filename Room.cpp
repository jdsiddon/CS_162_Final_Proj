#include "Room.hpp"

#define MOVE_UNAVAIL " - UNAVAILABLE - "
/*********************************************************************
 ** Function: Room
 ** Description: Default Room constructor. Used to create a Room that is
 ** inside the train. Connects the inside room's 'north' room connection
 ** to the previous train end car, sets the previous last room's
 ** 'south' pointer to the newly created room.
 ** Parameters: Room previousCar, last car in train to connect to. If
 ** this value is NULL then we are creating the first car in the train
 ** so we don't want to set the room's north pointer.
 ** Pre-Conditions: No Room created.
 ** Post-Conditions: Room created with north/south connections.
 *********************************************************************/
Room::Room(Room* previousCar) {
  setTrainSide("inside");
  setOutside(false);

  if(previousCar != NULL) { /* If previousCar is NULL, we are on the start of the train. */
    /* Connect new room to existing car at end of train last room. */
    setNorth(previousCar);

    /* Set previous car's south to the new room. */
    previousCar->setSouth(this);
  }
}

/*********************************************************************
 ** Function: Room
 ** Description: Secondary Room constructor. Used to create a Room that is on
 ** the outside of the train. Connects the outside room's 'north' room connection
 ** to the previous train end car, sets the previous last room's
 ** 'south' pointer to the newly created room.
 ** Parameters: string side, side of the train the 'outside' room is on.
 ** Room previousCar, last car in train to connect to. If
 ** this value is NULL then we are creating the first car in the train
 ** so we don't want to set the room's north pointer.
 ** Pre-Conditions: No 'outside' Room created.
 ** Post-Conditions: outside Room created with north/south connections.
 *********************************************************************/
Room::Room(std::string side, Room* previousCar) {
  setOutside(true); /* Make room on the outside. */
  setTrainSide(side); /* Set the side */

  if(previousCar != NULL) { /* If previousCar is NULL, we are on the end of the train. */
    /* Connect new room to last old last room. */
    setNorth(previousCar);

    /* Set previous car's south to the new room. */
    previousCar->setSouth(this);
  }
}

Room::~Room() {

}

/*********************************************************************
 ** Function: setOutside
 ** Description: Sets the 'outside' element of a room.
 ** Parameters: bool value, true or false if room is outside.
 ** Pre-Conditions: outside not set.
 ** Post-Conditions: outside set.
 *********************************************************************/
void Room::setOutside(bool value) {
  outside = value;
}

/*********************************************************************
 ** Function: getOutside
 ** Description: Returns if the room is outside, false if inside.
 ** Parameters: None.
 ** Pre-Conditions: outside status unknown.
 ** Post-Conditions: outside status known.
 *********************************************************************/
bool Room::getOutside() {
  return outside;
}

/*********************************************************************
 ** Function: setTrainSide
 ** Description: Sets the side of the train to a valid enum based on the
 ** passed string value.
 ** Parameters: string text, side of the train the room is on.
 ** Pre-Conditions: Room side not set.
 ** Post-Conditions: Room side set.
 *********************************************************************/
void Room::setTrainSide(std::string text) {
  if ( text == "east" ) {
    this->trainSide = east;    /* Set to valid enum value. */

  } else if ( text == "west" ) {
    this->trainSide = west; /* Set to valid enum value. */

  }
}

/*********************************************************************
 ** Function: getTrainSide
 ** Description: Gets the side of the train the room is on.
 ** Parameters: None.
 ** Pre-Conditions: Room side unknown.
 ** Post-Conditions: Room side known.
 *********************************************************************/
std::string Room::getTrainSide() {
  std::string side = " ";

  if ( this->trainSide == east ) {
    side = "east";

  } else if ( this->trainSide == west ) {
    side = "west";
  }

  return side;
}

/*********************************************************************
 ** Function: moveMenu
 ** Description: Prints out current movement options to the user
 ** based on the room.
 ** Parameters: None.
 ** Pre-Conditions: Room movement options unknown.
 ** Post-Conditions: Room movement options known.
 *********************************************************************/
Room* Room::moveMenu() {
  int selection = 0;
  Room *toMove;

  /* North options */
  std::cout << "1. Move North";
  if (getNorth())
    std::cout << " to" << (getNorth()->getOutside() ? " outside " : " inside ") << getNorth()->getRoomType() << std::endl;
  else
    std::cout << MOVE_UNAVAIL << std::endl;

  /* South options */
  std::cout << "2. Move South";
  if (getSouth())
    std::cout << " to" << (getSouth()->getOutside() ? " outside " : " inside ") << getSouth()->getRoomType() << std::endl;
  else
    std::cout << MOVE_UNAVAIL << std::endl;

  /* East options */
  std::cout << "3. Move East";
  if (getEast())
    std::cout << " to" << (getEast()->getOutside() ? " outside " : " inside ") << getEast()->getRoomType() << std::endl;
  else
    std::cout << MOVE_UNAVAIL << std::endl;

  /* West options */
  std::cout << "4. Move West";
  if (getWest())
    std::cout << " to" << (getWest()->getOutside() ? " outside " : " inside ") << getWest()->getRoomType() << std::endl;
  else
    std::cout << MOVE_UNAVAIL << std::endl;

  /* Get user input. */
  while (selection < 1 || selection > 4) {
    std::cout << "Enter movement: ";
    std::cin >> selection;

    if (selection == 1 && getNorth()) {  /* Check if they select north, and north is an option. */
      toMove = getNorth();  /* User wants to move north. */

    } else if (selection == 2 && getSouth()) { /* Check if they select south, and south is an option. */
      toMove = getSouth();  /* User wants to move south. */

    } else if (selection == 3 && getEast()) { /* Check if they select east, and east is an option. */
      toMove = getEast();   /* User wants to move east. */

    } else if (selection == 4 && getWest()) { /* Check if they select west, and west is an option. */
      toMove = getWest();   /* User wants to move west. */

    } else {      /* Selection was invalid. */
      std::cout << "Invalid Selection!" << std::endl;
      selection = 0;  /* Reset selection to invalid value so while loop continues. */
    }

  }

  return toMove;
}

/*********************************************************************
 ** Function: setSouth
 ** Description: Sets the south link of the room.
 ** Parameters: Room* room1, room to link.
 ** Pre-Conditions: Room link not set.
 ** Post-Conditions: Room link set.
 *********************************************************************/
void Room::setSouth(Room* room1) {
  southRoom = room1;
}

/*********************************************************************
 ** Function: setNorth
 ** Description: Sets the north link of the room.
 ** Parameters: Room* room1, room to link.
 ** Pre-Conditions: Room link not set.
 ** Post-Conditions: Room link set.
 *********************************************************************/
void Room::setNorth(Room* room1) {
  northRoom = room1;
}

/*********************************************************************
 ** Function: setEast
 ** Description: Sets the east link of the room.
 ** Parameters: Room* room1, room to link.
 ** Pre-Conditions: Room link not set.
 ** Post-Conditions: Room link set.
 *********************************************************************/
void Room::setEast(Room* room1) {
  eastRoom = room1;
}

/*********************************************************************
 ** Function: setWest
 ** Description: Sets the west link of the room.
 ** Parameters: Room* room1, room to link.
 ** Pre-Conditions: Room link not set.
 ** Post-Conditions: Room link set.
 *********************************************************************/
void Room::setWest(Room* room1) {
  westRoom = room1;
}

/*********************************************************************
 ** Function: getCurrent
 ** Description: Returns the current Room.
 ** Parameters: None.
 ** Pre-Conditions: Room unknown.
 ** Post-Conditions: Room known.
 *********************************************************************/
Room* Room::getCurrent() {
  return this;
}

/*********************************************************************
 ** Function: getSouth
 ** Description: Returns the south Room of the current Room.
 ** Parameters: None.
 ** Pre-Conditions: Room unknown.
 ** Post-Conditions: Room known.
 *********************************************************************/
Room* Room::getSouth() {
  return this->southRoom;
}

/*********************************************************************
 ** Function: getNorth
 ** Description: Returns the north Room of the current Room.
 ** Parameters: None.
 ** Pre-Conditions: Room unknown.
 ** Post-Conditions: Room known.
 *********************************************************************/
Room* Room::getNorth() {
  return this->northRoom;
}

/*********************************************************************
 ** Function: getEast
 ** Description: Returns the east Room of the current Room.
 ** Parameters: None.
 ** Pre-Conditions: Room unknown.
 ** Post-Conditions: Room known.
 *********************************************************************/
Room* Room::getEast() {
  return this->eastRoom;
}

/*********************************************************************
 ** Function: getWest
 ** Description: Returns the west Room of the current Room.
 ** Parameters: None.
 ** Pre-Conditions: Room unknown.
 ** Post-Conditions: Room known.
 *********************************************************************/
Room* Room::getWest() {
  return this->westRoom;
}
