#include "MusicClipPtr.h"

class Node {
  public:
    Node(MusicClipPtr);
    Node* getNext();
    void setNext(Node* newNext);
    MusicClipPtr getClip();

  private:
    MusicClipPtr clip;
    Node* next;
};
