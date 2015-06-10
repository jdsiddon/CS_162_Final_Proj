#include "Player.hpp"

/*********************************************************************
 ** Function: Player
 ** Description: Default player constructor, creates the player.
 ** Parameters: None.
 ** Pre-Conditions: No Player created.
 ** Post-Conditions: Player created not on the train.
 *********************************************************************/
Player::Player() {
  setName("Bob Smith");
  setBagLimit(5);
}

/*********************************************************************
 ** Function: Player
 ** Description: Secondary player constructor. Places the Player
 ** at the start of the train.
 ** Parameters: string text, players name. Train *train, Train that the
 ** Player is riding on.
 ** Pre-Conditions: No Player created.
 ** Post-Conditions: Player created on the train.
 *********************************************************************/
Player::Player(std::string text, Train *train) {
  setName(text); /* Set player name. */
  setBagLimit(5);

  /* Set first room to where player starts. */
  setCurrentRoom(train->getFirstRoom());

}

/*********************************************************************
 ** Function: setName
 ** Description: Sets the name of the Player.
 ** Parameters: string text, players name.
 ** Pre-Conditions: No Player name set.
 ** Post-Conditions: Player name set.
 *********************************************************************/
void Player::setName(std::string text) {
  name = text;
}

/*********************************************************************
 ** Function: getName
 ** Description: Gets the name of the Player.
 ** Parameters: None.
 ** Pre-Conditions: Player name unknown.
 ** Post-Conditions: Player name known.
 *********************************************************************/
std::string Player::getName() {
  return name;
}

/*********************************************************************
 ** Function: setBagLimit
 ** Description: Sets the number of items the Player can have in their bag.
 ** Parameters: int number, number of items the players bag can hold.
 ** Pre-Conditions: No bag limit set.
 ** Post-Conditions: Players bag limit set.
 *********************************************************************/
void Player::setBagLimit(int number) {
  bagLimit = number;
}

/*********************************************************************
 ** Function: getBagLimit
 ** Description: gets the number of items the Player can have in their bag.
 ** Parameters: None.
 ** Pre-Conditions: Bag limit unknown.
 ** Post-Conditions: Players bag limit known.
 *********************************************************************/
int Player::getBagLimit() {
  return bagLimit;
}

/*********************************************************************
 ** Function: setCurrentRoom
 ** Description: sets the Room the player is in.
 ** Parameters: Room *tempRoom, room the player is in.
 ** Pre-Conditions: Player not moved.
 ** Post-Conditions: Player moved to new room.
 *********************************************************************/
void Player::setCurrentRoom(Room *tempRoom) {
  currentRoom = tempRoom;
}

/*********************************************************************
 ** Function: getCurrentRoom
 ** Description: Gets the current Room the player is in.
 ** Parameters: None.
 ** Pre-Conditions: Player room unknown.
 ** Post-Conditions: Player room known.
 *********************************************************************/
Room* Player::getCurrentRoom() {
  return currentRoom;
}


/*********************************************************************
 ** Function: setSobriety
 ** Description: Sets the sobriety of the Player.
 ** Parameters: bool status, true if sober, false if drunk.
 ** Pre-Conditions: No sobriety set.
 ** Post-Conditions: Player sobriety set.
 *********************************************************************/
void Player::setSobriety(bool status) {
  sobriety = status;
}

/*********************************************************************
 ** Function: getSobriety
 ** Description: Gets the sobriety of the Player.
 ** Parameters: None.
 ** Pre-Conditions: Sobriety unknown.
 ** Post-Conditions: Sobriety known.
 *********************************************************************/
bool Player::getSobriety() {
  return sobriety;
}

/*********************************************************************
 ** Function: addToBag
 ** Description: Adds item to the players bag.
 ** Parameters: Item *item, pointer to Item to add to players bag.
 ** Pre-Conditions: Item not added to bag.
 ** Post-Conditions: Item added to bag.
 *********************************************************************/
void Player::addToBag(Item *item) {
  if(getBagLimit() <= getBagItems().size()) { /* Check bag limit. */
    std::cout << "Bag full!";

  } else {
    bag.push_back(item);

  }
}

std::vector<Item*> Player::getBagItems() {
  return bag;
}
