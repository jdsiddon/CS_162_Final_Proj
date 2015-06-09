/*********************************************************************
 ** Program Filename: Dice.hpp
 ** Author: Justin Siddon
 ** Date: 5/01/15
 ** Description: This file defines the methods of the Dice class
 ** used to 'roll' values for attacking and defending characters.
 ** Each Character has dice.
 ** Input: None.
 ** Output: None.
 *********************************************************************/

#ifndef DICE_HPP
#define DICE_HPP

class Dice {

private:
  int sides;
  int numDice;
  void setSideCount(int);
  void setDiceCount(int);

public:
  Dice();
  Dice(int, int);
  int rollDice();
  int getSideCount();
  int getDiceCount();

};


#endif
