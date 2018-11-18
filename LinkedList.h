#include "Node.h"

class LinkedList {
  public:
    // LinkedList();
    void push(Node*);
    Node* getHead();
    Node* getTail();

  private:
    Node* head;
    Node* tail;
};
