/*********************************************************************
 ** Program Filename: Queue.cpp
 ** Author: Justin Siddon
 ** Date: 5/23/15
 ** Description: This file defines defines the methods of the Queue clas.
 ** Queue is used to collect characters at start and characters that
 ** win after combat.
 ** Input: None
 ** Output: None
 *********************************************************************/

#include <cstdlib>
#include <iostream>
#include "Queue.hpp"

Queue::~Queue() {
  ListNode *nodePtr = head; /* Start at head of list */
  while(nodePtr != NULL) {
    ListNode *garbage = nodePtr;

    /* Get next node */
    nodePtr = nodePtr->next;

    /* Delete garbage */
    delete garbage;
  }
}

/*********************************************************************
 ** Function: add
 ** Description: Adds a value to the queue.
 ** Parameters: Room value, room on the train to add to train.
 ** Room leftValue, 'room' on the outside of the train to link to the
 ** train room. Room rightValue, 'room' on the inside of the train
 ** to link to the train room.
 ** Pre-Conditions: Value not added to queue.
 ** Post-Conditions: Value added to queue.
 *********************************************************************/
void Queue::add(Room *value, Room *leftValue, Room *rightValue) {

  if (head == NULL) {
    head = new ListNode(value);
    tail = head;  /* Initialize tail to point to head. */

    head->left = new ListNode(leftValue, head, "left");
    head->right = new ListNode(rightValue, head, "right");

  } else {
    ListNode *nodePtr = tail;
    ListNode *newNode = new ListNode(value);

    /* Set the newest node pointers previous to last previous one. */
    newNode->previous = nodePtr;

    /* Set the newest node outsideLeft and outsideRight spaces. */
    newNode->left = new ListNode(leftValue, newNode, "left");
    newNode->right = new ListNode(rightValue, newNode, "right");

    /* Set the old last pointer to point to the newest pointer. */
    nodePtr->next = newNode;

    /* Set tail of queue to last element. */
    tail = newNode;

    /* DEBUGGING CODE */
    // std::cout << "Node Address: " << &newNode->value << std::endl;
    // std::cout << "Previous: " << &newNode->previous->value << std::endl;
    // std::cout << "Next: " << &newNode->next->value << std::endl;
  }

  /* DEBUGGING CODE */
  ListNode *start = head; /* Start of Queue. */
  ListNode *nextNode;  /* Create pointer to next value pointer. */
  nextNode = start; /* Set to next node to 2nd node. */
  do {
    std::cout << "Train Room: " << nextNode->value->getRoomNumber() << std::endl;  /* Print out data. */
    std::cout << "Left Outside: " << nextNode->left->value->getRoomNumber() << std::endl;  /* Print out data. */
    std::cout << "Right Outside: " << nextNode->right->value->getRoomNumber() << std::endl;  /* Print out data. */
    nextNode = nextNode->next;
  } while(nextNode);
  /* END DEBUGGING CODE */

}

/*********************************************************************
 ** Function: remove
 ** Description: Removes first value from the queue.
 ** Parameters: None.
 ** Pre-Conditions: All values still in queue.
 ** Post-Conditions: First value removed from queue.
 *********************************************************************/
Room* Queue::remove() {
  ListNode *ptr = head; /* Start of list, also node to remove. */
  ListNode *nextNode;  /* Create pointer to next value pointer. */

  nextNode = ptr->next; /* Set to next node to 2nd node. */
  head = nextNode;      /* Head now points to 2nd node. */

  Room *roomRemoved = ptr->value;

  if(ptr) {
    /* Free memory */
    delete ptr;   /* Was 1st node before. */
    ptr = NULL;
  }
  return roomRemoved;
}

/*********************************************************************
 ** Function: getNode
 ** Description: returns first node is queue.
 ** Parameters: None.
 ** Pre-Conditions: All values still in queue.
 ** Post-Conditions: First value removed from queue.
 *********************************************************************/
Room* Queue::getCurrentNode() {
  if(head) {
    return head->value;
  } else {
    /*std::cout << "\nEMPTY!" << std::endl; DEBUGGING CODE */
    return NULL;
  }
}
