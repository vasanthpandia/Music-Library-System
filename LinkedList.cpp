#include "LinkedList.h"

// LinkedList::LinkedList() {
//   head = NULL;
//   tail = NULL;
//   // tail = NULL;
// }

void LinkedList::push(Node* node) {
  if(head == NULL) {
    head = node;
    tail = head;
  } else {
    // head->setNext(node);
    tail->setNext(node);
    tail = tail->getNext();
  }
}

Node* LinkedList::getHead() {
  return head;
}

Node* LinkedList::getTail() {
  return tail;
}
