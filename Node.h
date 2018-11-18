#include "MusicClipPtr.h"

class Node {
  public:
    Node(MusicClipPtr&);
    ~Node();
    Node* getNext();
    void setNext(Node* newNext);
    MusicClipPtr& getClip();
    // void setClip(MusicClipPtr&);

  private:
    MusicClipPtr& clip;
    Node* next;
};
