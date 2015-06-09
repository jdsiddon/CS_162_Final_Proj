/*********************************************************************
 ** Program Filename: Dice.cpp
 ** Author: Justin Siddon
 ** Date: 5/01/15
 ** Description: This file defines the methods of the Dice class
 ** used to 'roll' values for attacking and defending characters.
 ** Each Character has dice.
 ** Input: None.
 ** Output: None.
 *********************************************************************/

#include <iostream> // Debugging.
#include <stdlib.h>
#include <time.h>

#include "Dice.hpp"

/*********************************************************************
 ** Function: Dice
 ** Description: Default Dice constructor.
 ** Parameters: None.
 ** Pre-Conditions: No Dice created.
 ** Post-Conditions: Dice object created with 2 'die'
 ** each with 6 'sides' created.
 *********************************************************************/
Dice::Dice() {
  setSideCount(2);
  setDiceCount(1);
}

/*********************************************************************
 ** Function: Dice
 ** Description: Additional Dice constructor.
 ** Parameters: int sides, number of sides each 'dice' have. int numDice,
 ** total number of 'dice' that are rolled when rolled.
 ** Pre-Conditions: No Dice created.
 ** Post-Conditions: Dice object created.
 *********************************************************************/
Dice::Dice(int sides, int numDice) {
  setSideCount(sides);
  setDiceCount(numDice);
}

/*********************************************************************
 ** Function: setSideCount
 ** Description: Sets the number of sides dice have.
 ** Parameters: int number, number of sides each 'dice' have.
 ** Pre-Conditions: Dice has no sides specified.
 ** Post-Conditions: Dice has sides.
 *********************************************************************/
void Dice::setSideCount(int number) {
  sides = number;
}

/*********************************************************************
 ** Function: setDiceCount
 ** Description: Sets the number of dice to be rolled.
 ** Parameters: int number, number of dice each that will be rolled.
 ** Pre-Conditions: Dice has count specified.
 ** Post-Conditions: Dice has count of dice.
 *********************************************************************/
void Dice::setDiceCount(int number) {
  numDice = number;
}

/*********************************************************************
 ** Function: getDiceCount
 ** Description: Returns the number of Dice to be rolled.
 ** Parameters: None.
 ** Pre-Conditions: Dice count unknown.
 ** Post-Conditions: Dice count returned.
 *********************************************************************/
int Dice::getDiceCount() {
  return numDice;
}

/*********************************************************************
 ** Function: getSideCount
 ** Description: Returns the number of sides each Dice have.
 ** Parameters: None.
 ** Pre-Conditions: Dice side count unknown.
 ** Post-Conditions: Dice side count returned.
 *********************************************************************/
int Dice::getSideCount() {
  return sides;
}

/*********************************************************************
 ** Function: rollDice
 ** Description: 'Rolls' dice and returns the sum of the rolled dice
 ** total.
 ** Parameters: None.
 ** Pre-Conditions: Dice not rolled.
 ** Post-Conditions: Dice rolled with a sum of the roll returned.
 *********************************************************************/
int Dice::rollDice() {
  int rollSum = 0;    /* Initialize variable to 0 to store sum of roll. */

  for(int i = 0; i < getDiceCount(); i++) {
    rollSum += rand() % getSideCount() + 1; /* Generate random number between 1 and total number of faces, then add to rollSum.*/
  }
  return rollSum;       /* Return sum of the dice rolled. */

}
