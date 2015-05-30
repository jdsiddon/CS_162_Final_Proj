#ifndef QUEUE_HPP
#define QUEUE_HPP
#include <string>

#include "Room.hpp"

class Queue {

  protected:
    struct ListNode {
      Room *value;

      ListNode *next;
      ListNode *previous;

      ListNode *left; /* Left and right outsides of the train room.*/
      ListNode *right;

      /* Constructor */
      ListNode(Room *value1, ListNode *left1 = NULL, ListNode *right1 = NULL, ListNode *next1 = NULL, ListNode *previous1 = NULL) {
        value = value1;

        left = left1;
        right = right1;

        next = next1;
        previous = previous1;
      } /* End ListNode const */

      /* Constructor */
      /* Used for creating outside room's, position is if the outside is left or right of the train room.*/
      // centerNode is the node thats on the train.
      ListNode(Room *value1, ListNode *centerNode, std::string position, ListNode *next1 = NULL, ListNode *previous1 = NULL) {
        value = value1;

        /* We are on the left side of the train so don't have an additional left room. You can't
           go outside again when you are already outside. */
        if(position == "left") {
          right = centerNode;
          left = NULL;

        /* We are on the right side of the train so don't have an additional right room. You can't
           go outside again when you are already outside. */
        } else if(position == "right") {
          left = centerNode;
          right = NULL;

        }
        next = next1;
        previous = previous1;
      } /* End ListNode const */
      
    };

    ListNode *head;
    ListNode *tail;

  public:
    Queue() { head = NULL; }
    ~Queue();
    void add(Room*, Room*, Room*);
    Room* getCurrentNode();
    Room* remove();
    void adjacentNodes();

};

#endif
